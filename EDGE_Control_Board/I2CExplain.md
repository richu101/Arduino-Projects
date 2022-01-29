# **I2c Master (Transmitter)**



## Wire.beginTransmission(0x08) 

```diff
+    This is used to begin the transmission to the slave of address 0x08
```
## Wire.write("**Helloooo**");

```diff
-    This function will Send the string hello through i2c
```

#  **I2c Master (Transmitter)**

```
while (Wire.available()>0) { 
    int c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    Serial.print("");
  }
```

