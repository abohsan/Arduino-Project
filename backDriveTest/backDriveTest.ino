#include <ZumoMotors.h>

/*
   This example uses the ZumoMotors library to drive each motor on the Zumo
   forward, then backward. The yellow user LED is on when a motor should be
   running forward and off when a motor should be running backward. If a
   motor on your Zumo has been flipped, you can correct its direction by
   uncommenting the call to flipLeftMotor() or flipRightMotor() in the setup()
   function.
*/

#define LED_PIN 13
ZumoMotors motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
adjustRight();
delay(500);
adjustLeft();


}

void adjustRight() {


 
  motors.setLeftSpeed(-60);
  motors.setRightSpeed(0);
  delay(500);

  motors.setLeftSpeed(-60);
  motors.setRightSpeed(-60);
  delay(400);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(-60);
  delay(500);
 motors.setLeftSpeed(60);
  motors.setRightSpeed(60);
  delay(800);
}
void adjustLeft() {


 
  motors.setLeftSpeed(0);
  motors.setRightSpeed(-60);
  delay(500);

  motors.setLeftSpeed(-60);
  motors.setRightSpeed(-60);
  delay(400);

  motors.setLeftSpeed(-60);
  motors.setRightSpeed(0);
  delay(500);
 motors.setLeftSpeed(60);
  motors.setRightSpeed(60);
  delay(800);
}

