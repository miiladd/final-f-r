


#include "NewPing.h"
#define TRIGGER_PIN 3
#define ECHO_PIN 5
 
// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400   
 
// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
int enA = A0;
int in1 = 2; 
int in2 = 4; 
int enB = A1; 
int in3 = 7; 
int in4 = 8; 
void setup()
{
  pinMode(enA, OUTPUT);  
  pinMode(enB, OUTPUT); 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);  
  pinMode(in3, OUTPUT);  
  pinMode(in4, OUTPUT); 
  Serial.begin(9600);
}

void demoTwo(){
 
  // روشن شدن موتورها
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW); 
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  delay(5000);

  
  // خاموش شدن موتورها
  digitalWrite(in1, LOW);  
  digitalWrite(in2, LOW);   
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW);   
  delay(5000);
}
void loop(){
  distance = sonar.ping_cm();
	Serial.print("Distance = ");
	
	if (distance >= 40 || distance <= 2) 
	{
		Serial.println("Out of range");
    digitalWrite(in1, LOW); 
    digitalWrite(in2, HIGH);  
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW); 
    analogWrite(enA, 200);
    analogWrite(enB, 200);
	}
	else 
	{
		Serial.print(distance);
		Serial.println(" cm");
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW); 
    digitalWrite(in4, LOW); 
	}
	delay(500);
  
}