# **I2c Master (Transmitter)**

## Wire.begin();

```diff
This function is to set the device as I2C master
```

## Wire.beginTransmission(0x08) 

```diff
    This is used to begin the transmission to the slave of address 0x08
```
## Wire.write("**Helloooo**");

```diff
    This function will Send the string hello through i2c
```
## Wire.endTransmission();

```diff
   This function is to end the particular I2C Transmission
-   If the end condition is not transmitted then the I2C slave wil wate until the next data pack reach  
```

#  **I2c Slave (receiver)**

## Wire.begin(0x08);
```
This function is used to set the device as I2C slave with the address 0x08
```
### *Code to read data*

```
while (Wire.available()>0) { 
    int c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    Serial.print("");
  }
```

## Wire.availabel() 


```
This function will return how maney Bytes of data are there in the I2C bus to read

After a wire.read() function the return value of the Wire.availabel() function will decriment by 1

```


## Wire.read()
```
 This function will return a single Byte of data from the I2c bus
```
**Example:**  If We send " Hello " through I2C then the wire.read function will return H . In the next call it will return 