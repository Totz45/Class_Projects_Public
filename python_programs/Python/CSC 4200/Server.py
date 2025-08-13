# Tate Finley
# CSC 4200 -- Project 3
# Server.cpp -- send and receive packets from a server
import argparse
import socket
import logging
import struct
import threading
class Server:
    
    def __init__(self,port,logfile):
        self.port = port
        self.logfile = logfile

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
    parser.add_argument('-p','--port',type=int,required=True,help='Port the server listens on')
    parser.add_argument('-l','--logfile',type=str,required=True,help='The logfile to keep record of packets')
    args = parser.parse_args()

    server = Server(args.port,args.logfile)
    
    #get internal ip of the instance
    host = socket.gethostbyname(socket.gethostname()) 
    
    # create socket
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    server_addr = (host, server.port)

    try:
        #bind socket for server
        try:
            s.bind(server_addr)
        except OSError as a:
            print(f"Failed to bind socket: {a}")
        else:
            while True:
                #listen range
                s.listen(5)
                #connect socket
                connection, address = s.accept()
                #allows multiple clients to connect
                thread = threading.Thread(target=handle_client, args=(connection, address, server.logfile))
                thread.start()              

    except socket.error:
        print(f"Unable to connect to the server, check server and ports")
       
def handle_client(connect, addr, log):
    #log client
    ack = "Recieved connection from (IP, port): {}".format(addr)
    log_reply(log, ack)
    print(f"{ack}")
    while True:
        data = connect.recv(12)
        (version, mes_type, mes_length) = struct.unpack(">III", data)
        #detail header recieved
        print(f"Recieved data: version: {version} type: {mes_type} length: {mes_length}")
        message = connect.recv(mes_length).decode('utf-8')

        if message == "HELLO":
            ack = "HELLO"
            print(f"RECIEVED MESSAGE: {message}")
            log_reply(log, message)
        elif message == "DISCONNECT":
            print("DISCONNECTING CLIENT FROM SERVER")
            break
        elif version == 17:
            logAck = "VERSION ACCEPTED"
            print(f"{logAck}")
            log_reply(log, logAck)
            if mes_type == 1:
                ack = "LIGHTON"
                logAck = "EXECUTING SUPPORTING COMMAND: {}".format(ack)
                print(f"{logAck}")
                log_reply(log, logAck)
                ack = "SUCCESS"
                logAck = "returning SUCCESS"
                print(f"{logAck}")
            elif mes_type == 2:
                ack = "LIGHTOFF"
                logAck = "EXECUTING SUPPORTING COMMAND: {}".format(ack)
                print(f"{logAck}")
                log_reply(log, logAck)
                ack = "SUCCESS"
                logAck = "returning SUCCESS"
                print(f"{logAck}")
            else:
                logAck = "IGNORING UNKNOWN COMMAND: {}".format(message)
                print(f"{logAck}")
                log_reply(log, logAck)
                #UNKNOWN COMMAND RESPONSE not specified in assignment so assumed success
                ack = "SUCCESS"
                logAck = "returning SUCCESS"
                print(f"{logAck}")
        else:
            ack = "0"
            #log mismatch and continue to listen
            logAck = "VERSION MISMATCH"
            print(f"{logAck}")
            log_reply(log, logAck)
        if ack != "0":
            #send appropriate response
            respond = ack.encode('utf-8')
            header = struct.pack('>III', version, mes_type, len(respond))
            connect.send(header + respond)

def log_reply(logfile, reply):
    #code to log interaction
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