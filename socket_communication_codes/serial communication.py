import serial
import socket
#serial communication
ser=serial.Serial()
ser.baudrate=9600 #Serial Baudrate 
ser.port=("COM16") #Serial Port 
#socket communication
UDP_IP = "127.0.0.1" #IP
UDP_PORT = 6868
sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))
while True:
     data,addr = sock.recvfrom(1024)
     # buffer size is 1024 bytes, data is binary
     state=data.decode('ascii') #Conert to ASCII
     print(state)
data=bytes("state",'utf-8') ~#Conver bytes UTF8
ser.open() #Open Serial
ser.write(data) #Send to Arduion

