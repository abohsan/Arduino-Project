#include <ZumoMotors.h>

ZumoMotors motors;

void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motors.setLeftSpeed(-100);
  motors.setRightSpeed(0);
  delay(300);

//  motors.setLeftSpeed(-100);
//  motors.setRightSpeed(-100);
//  delay(400);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(-100);
  delay(300);
  motors.setLeftSpeed(100);
  motors.setRightSpeed(100);
  delay(300);
}
