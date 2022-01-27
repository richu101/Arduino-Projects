#include <Arduino_EdgeControl.h>

#define k -0.1  //slope value
#define c 38.1  //calibration value
void setup() {
  Serial.begin(9600);

  // Set the timeout
  auto startNow = millis() + 2500;
  while (millis() < startNow);
  Serial.println("Hello, Edge Control Sketch!");

    EdgeControl.begin();
    Power.on(PWR_3V3);
    Power.on(PWR_MKR2);
  // Enable power lines 
    Power.enable3V3();
    Power.enable5V();

 // pinMode(INPUT_05V_CH05,INPUT);
  // Start the I2C connection 
  Wire.begin();

  // Initialize the expander pins 
  Expander.begin();
  Expander.pinMode(EXP_LED1, OUTPUT);
}

void loop() {    
    // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x08); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  //  getPHvalue(INPUT_05V_CH05);
    
}
