
Arduino Code

#include <Servo.h>
// Defines Tirg and Echo pins of the Ultrasonic Sensor & the Buzzer pin
const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 9;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; 
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
  pinMode(buzzerPin, OUTPUT); // Sets the buzzerPin as an Output
  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  if (distance < 20) {
    tone(buzzerPin,1000);
  } else {
    noTone(buzzerPin);
  }
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  if (distance < 20) {
    tone(buzzerPin,1000);
  } else {
    noTone(buzzerPin);
  }
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}


