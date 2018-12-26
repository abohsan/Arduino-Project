
#include <ZumoMotors.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonicR(6);
Ultrasonic ultrasonicL(7);

ZumoMotors motors;


void setup() {

}

void loop() {
 motors.setLeftSpeed(100);
 motors.setRightSpeed(100);
}


//void AdjustAngle() {
//
//double R ;
//double L  ;
//
// Serial.print( R);
//    Serial.print(" , ");
//    Serial.print(L);
//    Serial.print(" , ");
//    Serial.println();
//
// 
//    while (doo) {
//      R = ultrasonicR.distanceRead() ;
//      delay (10);
//      L = ultrasonicL.distanceRead() ;
//      if (R < L) {
//        motors.setLeftSpeed(100);
//        motors.setRightSpeed(0);
//
//      } else if (R > L) {
//        motors.setLeftSpeed(0);
//        motors.setRightSpeed(100);
//
//      } else {
//
//        doo = false;
//        motors.setLeftSpeed(0);
//        motors.setRightSpeed(0);
//      }
//    }
//}

//void AdjustAngle() {
//
//
//  bool doo = false;
//  while(!doo){
//
//  delay (10);
//  R = ultrasonicR.distanceRead() ;
//  delay (10);
//  L = ultrasonicL.distanceRead() ;
//  delay (10);
//  angle=(atan(x) * 180 / 3.14);
//  newDelay = (55 *(angle)/90);
//
//
//
//
//  if ( R < L) {
//
//    x = ((L - R) / 8.0);
//    Serial.print( R);
//    Serial.print(" , ");
//    Serial.print(L);
//    Serial.print(" , ");
//    delay (10);
//    Serial.print(angle);
//    Serial.println();
//    for (int speed = 0 ; speed <= 104 ; speed++) {
//      motors.setLeftSpeed(speed);
//      motors.setRightSpeed(0);
//      delay(newDelay);
//
//    }
//
//  }
//  else if ( R > L ) {
//    x = ((R - L) / 8.0);
//    Serial.print( R);
//    Serial.print(" , ");
//    Serial.print(L);
//    Serial.print(" , ");
//    delay (10);
//    Serial.print(angle);
//    Serial.println();
//
//    for (int speed = 0 ; speed <= 104 ; speed++) {
//      motors.setRightSpeed(speed);
//      motors.setLeftSpeed(0);
//      delay(newDelay);
//    }
//
//  }else{
//    doo = true;
//    Serial.println("straight");
//  }
//
//
//  }
//  motors.setRightSpeed(0);
//  motors.setLeftSpeed(0);
//
//
//}

