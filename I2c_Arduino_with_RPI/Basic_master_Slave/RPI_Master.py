'''
from smbus import SMBus

addr = 0x8 # BUS addr
bus = SMBus(1) # Select i2c one in rpi
numb = 1

print("Enter 1 to ON and 0 to OFF")

while numb == 1:
    ledstate = int(input(">>>   "))
    if ledstate == 1:
        bus.write_byte(addr, 0x1)
    elif ledstate == 0:
        bus.write_byte(addr, 0x0)
    else:
        numb = 0 
'''

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeNumber(value):
    bus.write_byte(address, value)
    # bus.write_byte_data(address, 0, value)
    return -1

def readNumber():
    number = bus.read_byte(address)
    # number = bus.read_byte_data(address, 1)
    return number

while True:
    var = input("")
    if not var:
        continue
    writeNumber(var)
    number = readNumber()