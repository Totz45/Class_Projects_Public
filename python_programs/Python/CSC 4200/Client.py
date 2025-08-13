# Tate Finley
# CSC 4200 -- Project 3
# Client.cpp -- send and receive packets from a client
import argparse
import socket
import logging
import struct
import threading
class Client:
    
    def __init__(self,server,port,logfile):
        self.server = server
        self.port = port
        self.logfile = logfile
    
    @property
    def server(self):
        return self._server
    
    @server.setter
    def server(self, server):
        if not server:
            raise ValueError("Missing server")
        self._server = server

    @property
    def port(self):
        return self._port
    
    @port.setter
    def port(self, port):
        if not port:
            raise ValueError("Missing port")
        self._port = port
    
    @property
    def logfile(self):
        return self._logfile
    
    @logfile.setter
    def logfile(self, logfile):
        if not logfile:
            raise ValueError("Missing logfile")
        self._logfile = logfile

        

def main():
    #parse arguments for server, port, and logfile
    parser = argparse.ArgumentParser()
    parser.add_argument('-s','--server',type=str,required=True,help='IP address of the server')
    parser.add_argument('-p','--port',type=int,required=True,help='Port the server listens on')
    parser.add_argument('-l','--logfile',type=str,required=True,help='The logfile to keep record of packets')
    args = parser.parse_args()

    client = Client(args.server,args.port,args.logfile)
    
    # create socket
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    try:
        #connect socket
        s.connect((client.server, client.port))
        #pack message here
        message = "HELLO"
        version = 17
        message_type = 1 #change message_type for client to send LIGHTOFF
        message_length = len(message.encode('utf-8'))
        header = struct.pack('>III', version, message_type, message_length)
    
        #send packet to server
        s.send(header + message.encode('utf-8'))
        
        #recieve message from server
        messageReceived = s.recv(12)
        (versionS, message_typeS, message_lengthS) = struct.unpack('>III', messageReceived)
        print(f"Received Data, version: {versionS} type: {message_typeS} length: {message_lengthS}")
        message = s.recv(message_lengthS).decode('utf-8')

        #check version
        if versionS == 17:
            print("VERSION ACCEPTED")
            log_reply(client.logfile, "VERSION ACCEPTED")
            print(f"Received Message: {message}")
            log_reply(client.logfile, message)

            #if version accepted send command
            if message_type == 1: 
                command = "LIGHTON" 
            elif message_type == 2:
                command = "LIGHTOFF" 
            message_length = len(command.encode('utf-8'))
            header = struct.pack('>III', version, message_type, message_length)
            s.send(header + command.encode('utf-8'))
            
            messageReceived = s.recv(12)
            (versionS, message_typeS, message_lengthS) = struct.unpack('>III', messageReceived)
            print(f"Received Data, version: {versionS} type: {message_typeS} length: {message_lengthS}")
            message = s.recv(message_lengthS).decode('utf-8')
            print(f"Received message: {message}")
            log_reply(client.logfile, message)
            print("Command SUCCESSFUL")

            
            message = "DISCONNECT"
            message_length = len(message.encode('utf-8'))
            header = struct.pack('>III', version, message_type, message_length)
            s.send(header + message.encode('utf-8'))
            print("Sending DISCONNECT Message to server")

            #assume SUCCESS message
            log_reply(client.logfile, "SUCCESS")
            s.close()

        else:
            print("VERSION MISMATCH")
            log_reply(client.logfile, "VERSION MISMATCH")        
        
        #record output in logfile
        

    except socket.error:
        print(f"Unable to connect to the server, check server and ports")

def log_reply(logfile, reply):
    log = logging.getLogger('LogServer')
    log.setLevel(logging.INFO)

    handler = logging.FileHandler(logfile, 'a')
    handler.setLevel(logging.INFO)

    formatter = logging.Formatter('%(asctime)s - %(message)s')
    handler.setFormatter(formatter)

    log.addHandler(handler)

    log.info(reply)

    log.removeHandler(handler)


if __name__ == "__main__":
    main()