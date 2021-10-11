#include<Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  Wire.begin();     

}

void loop() {
  Wire.requestFrom(8,1);
  delay(10);
   byte MasterReceive = Wire.read(); // when clock is streched the wire.read function is returning 14
   if(MasterReceive != 255){ // TWI comminication in arduino is active low 
    Serial.println(MasterReceive);
   }
   else {
     
   }
    
   
}

