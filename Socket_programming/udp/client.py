
import socket 

name = socket.gethostname()
port = 12000

s = socket.socket(socket.AF_INET ,socket.SOCK_DGRAM)
message = input()
s.sendto(message.encode('ascii') , (name ,port))
modified_msg ,servaddr = s.recvfrom(2048)

print(modified_msg.decode('ascii'))
s.close()

