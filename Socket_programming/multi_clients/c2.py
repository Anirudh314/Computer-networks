import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())

port = 8883
s.connect((host, port))
#msg2 = (s.recv(1024)).decode("utf-8")

with open('sample.txt', 'w') as f:
	while True:    
		print('receiving data...')
		data = s.recv(1024).decode('ascii')
		print( data)
		f.write(data)
		if not data:
		    	f.close()
		    	break

print (data)


print (data)
s.close()

