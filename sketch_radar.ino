/*
  Hey Guys! Welcome to RENU ROBOTICS
  This is a Simple Project
  Ultrasonic Radar
  Hope you Like It!! 
*/

#include <Servo.h> // Including the Servo library

const int trigPin = 10;
const int echoPin = 11; // Defining Trig and Echo pins of the Ultrasonic Sensor

long duration;
int distance; // Variables for the duration and the distance

Servo myServo; // Creating a servo object for controlling the servo motor
void setup() 
{
  pinMode(trigPin, OUTPUT); // Setting the trigPin as an Output
  pinMode(echoPin, INPUT); // Setting the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(9); // Defining on which pin is the servo motor attached
}
void loop() {
  
  for(int i=15;i<=165;i++) // Rotates the servo motor from 15 to 165 degrees
  {  
  myServo.write(i);
  delay(30);
  distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  
  for(int i=165;i>15;i--) // Repeats the previous lines from 165 to 15 degrees
  {  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance() // Function for calculating the distance measured by the Ultrasonic sensor
{   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
