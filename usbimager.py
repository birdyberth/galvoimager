import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600)

t = time.time()
data = []

while True:
    d = ser.read()
    if d == b'\n':
        break
    data.append(d)
    #if len(d) <= 63:
    #    break
    #print(d)
print(len(data))
print(time.time()-t)
