#include <stdio.h>

#define BLINK_PIN 13
#define BUTTLED_PIN 12
#define BUTTON_PIN 7

int ON = HIGH;
int OFF = LOW;
int currentButtonState = OFF;

void setup(){
  pinMode(BLINK_PIN, OUTPUT);
  pinMode(BUTTLED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop(){
  
  if (digitalRead(BUTTON_PIN) == ON) {
    digitalWrite(BUTTLED_PIN, ON);
  }
  else {
    digitalWrite(BUTTLED_PIN, OFF);
  }
 
  digitalWrite(BLINK_PIN, ON);
  delay(1000);
  digitalWrite(BLINK_PIN, OFF);
  delay(1000);
  

}


