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
	_pin = 8;
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
#define trigPin1 53
#define echoPin1 51

#define trigPin2 49
#define echoPin2 47



void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
 
}
void loop() {
  
  //////////////////////right/////////////////
  long duration1, right;
  long duration2, left;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  right = (duration1/2) / 29.1;
  Serial.print("right is  ");
  Serial.println(right);
    ///////////////////left///////////////
   digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  left = (duration2/2) / 29.1;
  Serial.print("left is  ");
  Serial.println(left);
  
 ////////front///////////
	long RangeInCentimeters;
	ultrasonic.DistanceMeasure();// get the current signal time;
	RangeInCentimeters = ultrasonic.microsecondsToCentimeters();//convert the time to centimeters
	Serial.print("front ");
	Serial.println(RangeInCentimeters);//0~400cm
	
  
    delay(500);
}

    

