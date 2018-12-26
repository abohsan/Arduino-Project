#include <ZumoMotors.h>

ZumoMotors motors;


void setup() {
  // put your setup code here, to run once:

    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
   

}

void loop() {
  // put your main code here, to run repeatedly:
delay(4000);
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);

}
