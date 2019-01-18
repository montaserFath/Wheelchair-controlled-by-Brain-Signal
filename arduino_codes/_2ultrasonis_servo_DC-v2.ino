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
 
Ultrasonic ultrasonic(7);


#define trigPin 22
#define echoPin 23

#define trigPin2 24
#define echoPin2 25

 long  duration1,duration2, front,left , right;
int DC1 = 13;
int DC2 = 12;
int SPEED=11;
Servo myservo;
float a =1.6667;
float b=110;
float angle;
void setup() {
  //serial communication
  Serial.begin (9600);
  
  //for 2 ultrasonic sensors  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  //for DC drive
  pinMode(DC1, OUTPUT);
  pinMode(DC2, OUTPUT);

  pinMode(SPEED,OUTPUT);
  
  //for servo motor 
  myservo.attach(9);
}
void loop() {
  ///////////////////get front///////////////
  right = getRight();
///////////////////get leftt///////////////
  left = getLeft();
  //////////////////////get right/////////////////	
	ultrasonic.DistanceMeasure();// get the current signal time;
  
	 front= ultrasonic.microsecondsToCentimeters();//convert the time to centimeters
    /////////////////print/////////////////
 /*
 Serial.print("front is  ");
  Serial.println(front);
   Serial.print("right is  ");
  Serial.println(right);
  Serial.print("left is  ");
  Serial.println(left);
  */
  //////////////control///////////////
  if ( ultrasonic.microsecondsToCentimeters() <= 30)
  {
    if ( (getRight() < 30  && getLeft() > 30) || ( getRight() <= 30 && getLeft() <= 30))
    {
      angle = b-(a*(ultrasonic.microsecondsToCentimeters()));
      //left//
      myservo.write(angle);
      //FORWARD
      goFront(255);
      delay (550);
      //stop
     Stop();
      myservo.write(50);
       //FORWARD
    goFront(100);
    }
    else
    {
      //right//
       angle = -(a*(ultrasonic.microsecondsToCentimeters()));
      //left//
      myservo.write(angle);
      //FORWARD
      goFront(255);
      delay (550);
      //stop
      Stop();
      myservo.write(50); 
       //FORWARD
    goFront(100);
    }
  }
  else
    {
    //FORWARD
    goFront(100);
    }
  
}
int  getRight()
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
int  getLeft()
{
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration1 = pulseIn(echoPin2, HIGH);
  int left1 = (duration1/2) / 29.1;
  return(left1);
}
void goFront(int Speed)
{
  //FORWARD
      digitalWrite(DC1,HIGH);
      digitalWrite(DC2,LOW);
      analogWrite(SPEED,Speed);
}
void Stop()
{
  digitalWrite(DC1,LOW);
      digitalWrite(DC2,LOW);
}

    

