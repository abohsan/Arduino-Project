
#include <ZumoMotors.h>
#include <Ultrasonic.h>


Ultrasonic ultrasonicR(10);
Ultrasonic ultrasonicL(11);

bool doo = true;
ZumoMotors motors;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

}

void loop() {

  Serial.print( ultrasonicR.distanceRead());
    Serial.print(" , ");
    delay(1000);
    Serial.print(ultrasonicL.distanceRead());
    Serial.print(" , ");
  Serial.println();

  AdjustAngle();
}


void AdjustAngle() {

  double R ;
  double L  ;
  int side = 0;
  while (doo) {
    R = ultrasonicR.distanceRead() ;
    delay (10);
    L = ultrasonicL.distanceRead() ;
    delay (10);

    if (R < L) {
      if ( side != 1) {
        motors.setLeftSpeed(100);
        motors.setRightSpeed(0);
        side = 1;
      }


    } else if (R > L) {
      if ( side != 2) {
        motors.setLeftSpeed(0);
        motors.setRightSpeed(100);
        side = 2;
      }
    } else {

      doo = false;
      motors.setLeftSpeed(0);
      motors.setRightSpeed(0);
      Serial.print("DONE");

    }
  }
}



