import socket

# AF_INET required for TCP connection; AF_INET is a socket family
# socket.socket(socket_family, socket_type)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())
port = 8883
s.bind((host, port))
s.listen(5)
# connection => connection object
# address => client ip address and remote ip
connection, address = s.accept()


#data = (connection.recv(1024)).decode('ascii')
#print(data)


#with open('received_file.txt', 'w') as f:

f=open('recieved_file.txt','w')

	
data = (connection.recv(1024)).decode('ascii')
print(data)

print ('file opened')
f.write(data)
print('receiving data...')
	


#f.write(data)
#data = connection.recv(1024).decode('ascii')


"""if not data:
			f.close()
			break"""
        # write data to a file
#f.write(data)
"""  """
print (data)

connection2, address2 = s.accept()
connection2.send(data.encode('ascii'))

connection.close()
connection2.close()

s.close()

