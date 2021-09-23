
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


