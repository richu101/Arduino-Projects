#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // slave addr = 8


int number = 0;
int state = 0;
const int buttonPin = 2;
int ledPin = 13;
void setup() {

    DDRB |= (1<<PB5);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600); 
    init_timer1();
    Wire.begin(SLAVE_ADDRESS);
    
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
    Serial.println("Ready!");
 
}
void init_timer1()
{
    TCCR0B |= (1<<CS01) | (1<<CS00);
    // set the (clk i/o) clock speed 16MHz / 64
    // 16/64 tick of the clock will increase the timer value by 1
}

void loop() {
 
 delay(100);
  
}


void receiveData(int byteCount){
  
    while(Wire.available()) {
       number = Wire.read();
       Serial.print("data received: ");
       Serial.println(number);
     
    }
}

void sendData(){
    bool  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
        
        TWCR |= (1<<TWEA); // set not acknowledge condition
        PORTB |= (1<<PB5); // this not working
    
  }
  else{
      TWCR &= ~(1<<TWEA); // set not acknowledge condition
      PORTB &= ~(1<<PB5);
  }
    Wire.write(TCNT0);
}