
import time
from smbus import SMBus

addr = 0x8 # BUS addr
bus = SMBus(1) # Select i2c one in rpi
numb = 1


while True:

    read = bus.read_byte(addr)
    time.sleep(3) 
