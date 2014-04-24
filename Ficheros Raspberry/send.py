import serial
import time
import sys

arduino0 = serial.Serial(sys.argv[1], 9600)
time.sleep(1);
arduino0.write(sys.argv[2])
time.sleep(1);
print('Codigo enviado')
arduino0.close() 

