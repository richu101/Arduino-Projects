

// if any doubt in lcd connectiobn reffer to this tutorial https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Wire.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long rpmtime;
float rpmfloat;
unsigned int rpm;
bool tooslow = 1;

void setup() {
  lcd.begin(16, 2);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS12); //Prescaler 256
  TIMSK1 |= (1 << TOIE1); //enable timer overflow
  pinMode(2, INPUT);
  attachInterrupt(0, RPM, FALLING);
}

ISR(TIMER1_OVF_vect) {
  tooslow = 1;
}

void loop() {
  delay(1000);
  if (tooslow == 1) {
    lcd.setCursor(0, 1);
      lcd.print("SLOW!");
  }
  else {
    rpmfloat = 120 / (rpmtime/ 31250.00);
    rpm = round(rpmfloat);
   lcd.clear();
   lcd.setCursor(1,0);
    lcd.print(rpm);
  }
}

void RPM () {
  rpmtime = TCNT1;
  TCNT1 = 0;
  tooslow = 0;
}
