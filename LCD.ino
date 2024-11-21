#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 4, 5, 6, 11); 

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 12;
const int buzzerPin = 13;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Distance:    ");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; 

  lcd.setCursor(0, 1); 
  lcd.print(distance);
  lcd.print(" cm    "); 
  
  if (distance < 20) { 
    digitalWrite(ledPin, HIGH); 
    tone(buzzerPin, 1000); 
  } else {
    digitalWrite(ledPin, LOW); 
    noTone(buzzerPin); 
  }

  delay(500); 
}