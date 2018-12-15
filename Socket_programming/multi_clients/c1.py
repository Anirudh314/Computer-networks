import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())

port = 8883
s.connect((host, port))

#send file


f=open("sample.txt","r")
l = f.read(1024)
while(l):
	print("sending")
	print(l)
	s.send(l.encode())
	l=f.read(1024)
	
	#s.send(l.encode('ascii'))
	
f.close()
print("done sending")

"""  """
msg2 = (s.recv(1024)).decode('ascii')
print (msg2)
s.close()

