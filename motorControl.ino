#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

int rightMotorSpeed = 40; //set motor speeds
int leftMotorSpeed = 40;

int blink_state;
long prevTime;

void setup() {
  AFMS.begin();
  rightMotor->setSpeed(rightMotorSpeed);
  leftMotor->setSpeed(leftMotorSpeed);
  
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0){
     blink_state = Serial.parseInt();
   }
   if (blink_state == 1){
     rightMotor->run(BACKWARD);
     leftMotor->run(BACKWARD);
   }
   else if (blink_state == 2){
     rightMotor->run(FORWARD);
     leftMotor->run(FORWARD);
   }
   else{
     rightMotor->run(RELEASE);
     leftMotor->run(RELEASE);
   }
   Serial.println(blink_state);
}
