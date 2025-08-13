# Tate Finley
# CSC 4200 -- Project 2
# Server.cpp -- send and receive packets from a server
import argparse
import socket
import logging
import random
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
    
    #replace with internal ip of the instance that the program is running
    host = '10.128.0.3' 
    
    # create socket
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    try:
        #bind socket for server
        try:
            s.bind((host, server.port))
        except OSError as a:
            print(f"Failed to bind socket: {a}")
        else:
            #listen range
            s.listen(5)
        
            #read quotes.txt file
            with open("quotes.txt", "r") as file:
                quote = file.readlines()
            #connect socket
            connection, address = s.accept()

            bufferSize = 1024
        
            #read message
            message = connection.recv(bufferSize).decode()

            #acknowledge and send quote
            if message == 'network':
                random_line = random.choice(quote)
                connection.send(random_line.encode())
                #send message to server
            else:
                connection.send('Connection rejected'.encode())
                #recieve message from server
        
        
            #record output in logfile
            log_reply(server.logfile, message)

    except socket.error:
        print(f"Unable to connect to the server, check server and ports")

    finally:
        s.close()

def log_reply(logfile, reply):
    #code to log interaction
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