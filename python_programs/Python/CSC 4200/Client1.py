# Tate Finley
# CSC 4200 -- Project 1
# Client.cpp -- send and receive packets from a client
import argparse
import socket
import logging
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

        #read message
        message = input("Message to send to server: ")

        #send message to server
        s.send(message.encode())

        #recieve message from server
        bufferSize = 1024
        messageReceived = s.recv(bufferSize)
        print("Recieved: ", messageReceived.decode())
        
        #record output in logfile
        log_reply(client.logfile, messageReceived.decode())

    except socket.error:
        print(f"Unable to connect to the server, check server and ports")

    finally:
        s.close()

def log_reply(logfile, reply):
    log = logging.getLogger('LogServer')
    log.setLevel(logging.INFO)

    handler = logging.FileHandler(logfile, 'w')
    handler.setLevel(logging.INFO)

    formatter = logging.Formatter('%(asctime)s - %(message)s')
    handler.setFormatter(formatter)

    log.addHandler(handler)

    log.info(reply)

    log.removeHandler(handler)


if __name__ == "__main__":
    main()