# HOW IT WORKS

## Circuit

* connect ATMEGA328 28th pin  to  RPI 5th pin
* connect ATMEGA328 27th pin  to  RPI 3th pin
* RPI GND to ATMEGA328 GND

## slave side 

* upload the **i2c_slave_arduino.ino** code to your slave arduino
* connect the LED to the PB5 or 13th pin of arduino with a 330 ohm resistor

## Master 

* Turn on the i2c1 in the Raspberry pi by typing the following command in the terminal 

```

 sudo raspi-config

```

* Navigate to Interface option using arrow key and hit enter
* Go down to i2c the hit YES
* Then run the [RPI_Master.py](https://github.com/richu101/Arduino-Projects/blob/master/I2c_Arduino_with_RPI/RPI_Master.py) python file in the terminal 

* Enter '1' to turn on the led in the slave and '0' to turn of the led

**See the magic of i2c**

# WARNING

DONT make the ATMEGA328 as maste and RPI as slave without a logic converter

RPI is 3.3v logic and  ATMEGA328 is 5v logic 

sending data from 5v logic to 3.3v logic will burn your RPI
