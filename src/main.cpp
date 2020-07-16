#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  Serial.println("Bereit...");
  mySwitch.enableTransmit(10);
  mySwitch.setProtocol(4);
}

void loop() {
  //runter
  Serial.println("Runter...");
  mySwitch.sendQuadState("Q00011Q0010FQ0000101");
  mySwitch.sendQuadState("Q00011Q0010FQ000010Q");
  
  delay(5000);
  
  //Stopp
  Serial.println("Stopp...");
  mySwitch.sendQuadState("Q00011Q0010FQ00FFFFF");
  
  delay(1000);
  
  //rauf
  Serial.println("Rauf...");
  mySwitch.sendQuadState("Q00011Q0010FQ0000F0F");
  mySwitch.sendQuadState("Q00011Q0010000000F00");
  
  delay(5000);
  
  //Stopp
  Serial.println("Stopp...");
  mySwitch.sendQuadState("Q00011Q0010FQ000FFFF");
  
  delay(1000);
}