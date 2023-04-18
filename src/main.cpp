#include <Arduino.h>

void setup() {
  int trigPin = 12;    // TRIG pin
  int echoPin = 14;    // ECHO pin

  float duration_us, distance_cm;
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}