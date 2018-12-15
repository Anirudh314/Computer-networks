from socket import *
port = 12000

s = socket(AF_INET ,SOCK_DGRAM)
s.bind(('',port))


print("server is ready to recieve")

message,cliaddr=s.recvfrom(2048)
print(message.decode('ascii'))

modified_msg=message.upper()
s.sendto(modified_msg ,cliaddr)
	
	
