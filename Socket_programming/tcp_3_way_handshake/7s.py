from socket import *
port =9091
socket = socket(AF_INET ,SOCK_STREAM)
socket.bind(('',port))
socket.listen(1)
print("server is ready to listen")


conn , addr = socket.accept()
sentence = conn.recv(1024).decode('ascii')
print(sentence)
c=sentence.upper()
#d="REQUEST".encode('ascii')
print(c)
#print(len(c))
#if d==c:
print("its requesting")
conn.send(c.encode('ascii'))
sen=conn.recv(1024)
print(sen)

conn.close()

