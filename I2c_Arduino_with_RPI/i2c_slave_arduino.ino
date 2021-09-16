#include<Wire.h>

void setup()
{
  // i2c slave addr 8
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent);

  DDRB |= (1<<5); // output mode
  PINB |= (1<<5); // output low  
  
}

void receiveEvent( int howMany) 
{

  while(Wire.available())
  {
    char c = Wire.read();
    digitalWrite(13,c);
  }
}

void loop()
{
  delay(100);
}
