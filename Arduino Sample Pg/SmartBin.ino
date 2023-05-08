#include <Servo.h>

Servo servo1;

// defines pins numbers
const int trigPin = 4;  //D2
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  servo1.attach(2);  //D4
  servo1.write(0);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  if (trigPin >= 3)
    Serial.println("Object found");
  else
    Serial.println("No Object found");
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance < 3) {
    Serial.print("Person is nearby open the lid");
    servo2();
  }
  else
  {
    servo3();
    Serial.print("Lid Closed");
  }
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(700);
}
void servo2() {
  servo1.write(90);
  delay(1000);
}
void servo3() {
  servo1.write(0);
  delay(1000);
}
