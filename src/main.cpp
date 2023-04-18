
#include <Arduino.h>

int trigPin = 12;    // TRIG pin
int echoPin = 14;    // ECHO pin
float duration_us, distance_cm;

const int PIN_RED   = 16;
const int PIN_GREEN = 5;
const int PIN_BLUE  = 4;

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}


void setup() {
  // begin serial port
  Serial.begin (9600);
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  if (distance_cm < 120) {
    Serial.print("Fult plass");
        setColor(0, 255, 255);

  } else {
        Serial.print("Det er plass");
            setColor(0, 0, 255);

    }

  delay(500);
}
