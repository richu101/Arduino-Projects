#define TRIGPIN 11 //Rx
#define ECHOPIN 10 //Tx
#define buttonpin 2
#include <Servo.h>

Servo myservo;  
int pos = 0;
 bool bstate;
 bool blaststate = 1,distancestate,bst;                                                                                                                
                                                                         

float duration, distance;

  double getdistance();
 
void setup() {
  // Set up serial monitor
  Serial.begin(115200);
 
  // Set pinmodes for sensor connections
  pinMode(ECHOPIN, INPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(13,OUTPUT);
  myservo.attach(9);
}
 
void loop() {

 bstate = digitalRead(buttonpin);
  delay(10);

  if(bstate == LOW)bst=1;
  else bst= 0;
  

if(bst==1)
{
 digitalWrite(13,HIGH);
if(distancestate == 0 && getdistance()<=10)
{

  myservo.write(0);
  Serial.println("Drop");
  delay(5000);
  myservo.write(180);
  distancestate = 1;
}

if(distancestate == 1 && getdistance()>20)
{
  distancestate = 0;
}
 Serial.print("Button last state = ");
 Serial.println(bst);   
}
if(bst == 0)
{
  myservo.write(0);
  Serial.println("Open");
  digitalWrite(13,LOW);
}
}

 double getdistance()
  {
      digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance =  ((duration / 2) * 0.343);
  Serial.print("Distance = ");
  Serial.println(distance/10);    
  return distance/10;
  }

 
