#include <Arduino_EdgeControl.h>
#include <Wire.h>


#define EDGE_I2C_ADDR 0x08
uint8_t inval[] = {1,2,3,4};

// Connect the MKR Board in the mkr slot 1 in the edge control board
// slot near the usb bort
byte x = 0;
void setup() {
 
  // Set the timeout
  auto startNow = millis() + 2500;
  while (millis() < startNow);
  initBoard();
 
 }

void loop() {    
    // put your main code here, to run repeatedly:

writeBytes(inval[2]);
delay(5000);
  //  getPHvalue(INPUT_05V_CH05);
    
}



void initBoard()
{   
    EdgeControl.begin();

    Serial.begin(9600);
    delay(3000);

    Serial.println("Init begin");

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);
    Power.on(PWR_MKR1);

    Wire.begin();

    Serial.print("IO Expander initializazion ");
    if (!Expander.begin()) {
        Serial.println("failed.");
        Serial.println("Please, be sure to enable gated 3V3 and 5V power rails");
        Serial.println("via Power.enable3V3() and Power.enable5V().");
    }
    else Serial.println("succeeded.");

}


void writeBytes(uint8_t i)
{
    Serial.println("Writing values");
    Wire.beginTransmission(EDGE_I2C_ADDR);

    
        Serial.print(i); 
        Serial.print(" ");
        Wire.write(i);
    

    Serial.println();

    Wire.endTransmission();
}
