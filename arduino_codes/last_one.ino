#include<Servo.h>
#include "Arduino.h"
class Ultrasonic
{
	public:
		Ultrasonic(int pin);
        void DistanceMeasure(void);
		long microsecondsToCentimeters(void);
		long microsecondsToInches(void);
	private:
		int _pin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
        long duration;// the Pulse time received;
};
Ultrasonic::Ultrasonic(int pin)
{
	_pin = 7;
}
/*Begin the detection and get the pulse back signal*/
void Ultrasonic::DistanceMeasure(void)
{
    pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_pin,LOW);
	pinMode(_pin,INPUT);
	duration = pulseIn(_pin,HIGH);
}
/*The measured distance from the range 0 to 400 Centimeters*/
long Ultrasonic::microsecondsToCentimeters(void)
{
	return duration/29/2;	
}
/*The measured distance from the range 0 to 157 Inches*/
long Ultrasonic::microsecondsToInches(void)
{
	return duration/74/2;	
}
 
Ultrasonic ultrasonic(7);


#define trigPin 22
#define echoPin 23
 long duration2, front, right;
int DC1 = 13;
int DC2 = 12;
int SPEED=11;
Servo myservo;
float a =1.6667;
float b=110;
float angle;
#include <SoftwareSerial.h>
#include<Servo.h>
#define rxPin 0
#define txPin 1

SoftwareSerial mySerial(rxPin, txPin); // RX, TX
char myChar ; 
char prevState;
char state;
void setup() {
  Serial.begin(9600);   
myservo.attach(9);

  //for 2 ultrasonic sensors  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //for DC drive
  pinMode(DC1, OUTPUT);
  pinMode(DC2, OUTPUT);

  pinMode(SPEED,OUTPUT);
  
}
void loop(){
  ///////////////////get front///////////////
  right = getFront();

  //////////////////////get right/////////////////
	
	ultrasonic.DistanceMeasure();// get the current signal time;
  
	 front= ultrasonic.microsecondsToCentimeters();//convert the time to centimeters
	//right = ultrasonic.microsecondsToCentimeters();//convert the time to centimeters
    /////////////////print/////////////////
  Serial.print("front is  ");
  Serial.println(front);
   Serial.print("right is  ");
  Serial.println(right);
 //////////////control///////////////
  if ( front < 30 )
  {
    if ( right < 30 )
    {
      angle = b-(a*front);
      //left//
      myservo.write(angle);
      //FORWARD
      goFront(250);
      delay (750);
      //stop
     Stop();
     // delay(1000);
      ///center//
      myservo.write(55);
    }
    else
    {
      //right//
      myservo.write(10);
      //FORWARD
      goFront(250);
      delay (750);
      //stop
      Stop();
      //delay(1000);
      ///center//
      myservo.write(55); 
    }
  }
  else
    {
     while (Serial.available() > 0) {
     //prevState=state;
  char inByte = Serial.read();
  // state=inByte ;
 // if (state=!prevState){
  switch ( inByte) {   
    ////////forward////////////
   case 'f': 
    //forward
goFront(150);
break;
   ///////backward///////////////
case 'b': 
    //backward
goBack(150);
break;
///////stop///////////////
case 's': 
    //stop
Stop();
break;
///////go right///////////////
case 'r':
myservo.write(10);
goFront(250);
delay(800);
Stop();
myservo.write(55);
   break;
    ///////////go left////////////
    case 'l':
myservo.write(110);  
goFront(250);
delay(800);
Stop();
myservo.write(55);
    break;
    ////////////error//////////////
default:
myservo.write(55);
      Serial.println('error');
    break;    
  } 
  }
    }
 
}
int  getFront()
{
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration2 = pulseIn(echoPin, HIGH);
  int front1 = (duration2/2) / 29.1;
  return(front1);
}
void goFront(int Speed)
{
  //FORWARD
      digitalWrite(DC1,HIGH);
      digitalWrite(DC2,LOW);
      analogWrite(SPEED,Speed);
}
void goBack(int Speed)
{
  //FORWARD
      digitalWrite(DC1,LOW);
      digitalWrite(DC2,HIGH);
      analogWrite(SPEED,Speed);
}
void Stop()
{
  digitalWrite(DC1,LOW);
      digitalWrite(DC2,LOW);
}

