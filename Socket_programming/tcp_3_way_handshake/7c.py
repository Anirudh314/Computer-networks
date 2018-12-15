import socket
import sys
name=socket.gethostname()
#name='10.24.37.3'
port =9091
s = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)
s.connect((name,port))
sentence=input()
s.send(sentence.encode('ascii'))
modified_sentence=s.recv(1024)


print("modified " + modified_sentence.decode('ascii'))


s.send("3 way handshake complete".encode('ascii'))

s.close()
