#include <Arduino.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "theoffice";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "tronderbest";     // The password of the Wi-Fi network
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
  Serial.begin(9600);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
  // begin serial port
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
  Serial.println("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  if (distance_cm < 120) 
  {
  Serial.println("Fult plass");
  setColor(0, 255, 255);
  } 
  else 
  {
  Serial.println("Det er plass");
  setColor(0, 0, 255);
  }
  delay(1000);
}