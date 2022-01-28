// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() 
{
  
  Wire.begin(0x08);                 // join i2c bus with address #8
  Wire.onReceive(receiveEvent);    // register event
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);             // start serial for output

}

void loop() {
  digitalWrite(LED_BUILTIN,LOW);
  delay(100);
} 






void receiveEvent(int howMany) 
{
  Serial.println("Receive event");
  digitalWrite(LED_BUILTIN,HIGH);
  while (Wire.available()>0) { // loop through all but the last
    int c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
    Serial.print("");
  }
  // int x = Wire.read();    // receive byte as an integer
  // Serial.println(x);         // print the integer
}
