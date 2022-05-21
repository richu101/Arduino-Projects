//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
String a;
void setup()
{
  radio.begin();
  Serial.begin(9600);
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  //Send message to receiver
  while(Serial.available()) {

a= Serial.readString();// read the incoming data as string


   radio.write(&a, sizeof(a));
  }
  
}
