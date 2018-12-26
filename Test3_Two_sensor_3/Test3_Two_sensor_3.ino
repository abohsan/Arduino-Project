#include <ZumoMotors.h>
#include <Ultrasonic.h>



ZumoMotors motors;
Ultrasonic ultrasonicL(22);
Ultrasonic ultrasonicR(24);
Ultrasonic ultrasonicSide(26);

const int pingPinLeft=22; 
const int pingPinRight=24;
const int pingPinSide=26;

unsigned long time;
bool doo = true;




double duration, distance; // Duration used to calculate distance
double TheDifferent = 4.0;
float distFrontRightmm, distFrontLeftmm;
double target = 62.0;

double maxx = (target + 0.5);
double minn = (target - 0.5);
int direction1 = 0;
float distBetweenAngleSensorsmm=160; //use ruler to find distance between the angle sensors, in mm
  int xPositioncm;
double adjustMaxx = (maxx + 1);
double adjustMinn = (minn - 1);
boolean isTheRoboticInTheRightSpotStage_1 = false ;


void setup() {
  Serial.begin (9600);

}


void loop() {

driveTheRoboticToStage_1() ;
  //driveTheRoboticToStage_1();
  // Serial.println( ultrasonicSide.distanceRead());
  //AdjustAngle();
}


void driveTheRoboticToStage_1() {

  /*
        delay to allow the robotic to skip the box before it depends on Ultrasonic Sensor.
        The delay time may change relativaly to the robotic speed.
  */
  time = millis();
  Serial.println(time);
  if (time < 3000) {
    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
    delay(3000);
  }
  // Get the distance and store it on the @distance
  distance = ultrasonicSide.distanceRead();
  // if the distance more than maximum distance or less than the minimum distance then call the method inside if statement.

  // if the distance less than the minimum distance then call turnLeft method
  if ( distance < minn  && time < 18000) { // turn to left.
    // calling the turnLeft method.
    // the turnLeft mathed take the current side distance.
    turnLeft(ultrasonicSide.distanceRead());
    // else if the distance more than the maximum distance then call turnRight method
  }   else if ( distance > maxx  && time < 18000) { // turn to right
    // calling the turnLeft method.
    // the turnLeft mathed take the current side distance.
    turnRight(ultrasonicSide.distanceRead());
  } else if (time < 18000) {
    // Drive strait
    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
  } else {

    if ( isTheRoboticInTheRightSpotMethod() ) {
      isTheRoboticInTheRightSpotStage_1 = isTheRoboticInTheRightSpotMethod();
    } else {
      doSafetyStep();
    }

  }

}


void doSafetyStep() {

  if (ultrasonicSide.distanceRead() > adjustMaxx ) {
    adjustRight();
    direction1 = 0;
    delay(200);

  } else if ( ultrasonicSide.distanceRead() < adjustMinn ) {
    adjustLeft();
    direction1 = 1;
    delay(200);
  } else {
    if (direction1 == 0) {
      adjustRight() ;
      delay(200);
    } else if (direction1 == 1) {
      adjustLeft();
      delay(200);
    }
  }


}


boolean isTheRoboticInTheRightSpotMethod() {
  if (ultrasonicR.distanceRead() < TheDifferent) {
    return true;
  } else {
    return false;
  }
}




void turnLeft(double dis) {
  motors.setLeftSpeed(30);
  motors.setRightSpeed(60);
}

void turnRight(double dis) {
  motors.setLeftSpeed(60);
  motors.setRightSpeed(30);
}

void adjustRight() {

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(0);
  delay(300);

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(-100);
  delay(400);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(-100);
  delay(300);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(20);
  doo = true;
   AdjustAngle();

  motors.setLeftSpeed(80);
  motors.setRightSpeed(80);
  delay(700);
}

void adjustLeft() {

  motors.setLeftSpeed(0);
  motors.setRightSpeed(-100);
  delay(300);

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(-100);
  delay(400);

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(0);
  delay(300);
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(20);
  doo = true;
  AdjustAngle() ;
  
  motors.setLeftSpeed(80);
  motors.setRightSpeed(80);
  delay(700);
}
//void AdjustAngle() {
//
//  double R ;
//  double L ;
//
//  while (doo) {
//    delay (300);
//    R = ultrasonicR.distanceRead() ;
//    delay (10);
//    L = ultrasonicL.distanceRead() ;
//    delay (10);
//    if (L > R) {
//      motors.setLeftSpeed(100);
//      motors.setRightSpeed(0);
//
//    } else if (R > L) {
//      motors.setLeftSpeed(0);
//      motors.setRightSpeed(100);
//
//    } else {
//
//      doo = false;
//      motors.setLeftSpeed(0);
//      motors.setRightSpeed(0);
//    }
//  }
//  delay (30);
//  motors.setLeftSpeed(100);
//  motors.setRightSpeed(100);
//}
void AdjustAngle(){
  float x;
  float angleDeg;
  float angleDelay;
  bool straight = false;
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);
  while (straight == false) {
    delay (100);
    ultrasonicReadFrontRightmm();
    Serial.print(distFrontRightmm);
    Serial.print(" , ");
    delay (100);
    ultrasonicReadFrontLeftmm();
    Serial.print(distFrontLeftmm);
    Serial.print(" , ");
    delay (100);
    if ((abs(distFrontRightmm - distFrontLeftmm)) < 5) {
      straight = true;
      Serial.println("Straight");
    }
    if ( straight == false && distFrontRightmm < distFrontLeftmm) {
      x = ((distFrontLeftmm - distFrontRightmm) / distBetweenAngleSensorsmm);
      Serial.print(x);
      Serial.print(" , ");
      angleDeg = ((atan(x)) * 180 / 3.14);
      Serial.print(angleDeg);
      Serial.print(" , ");
      angleDelay = (65 * angleDeg / 90);
      Serial.println(angleDelay);
      for (int speed = 0 ; speed <= 104 ; speed++) {
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(0);
        delay(angleDelay);
      }
      motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
    }
    if ( straight == false && distFrontRightmm > distFrontLeftmm ) {
      x = ((distFrontRightmm - distFrontLeftmm) / distBetweenAngleSensorsmm);
      Serial.print(x);
      Serial.print(" , ");
      angleDeg = ((atan(x)) * 180 / 3.14);
      Serial.print(angleDeg);
      Serial.print(" , ");
      angleDelay = (65 * angleDeg / 90);
      Serial.println(angleDelay);
      for (int speed = 0 ; speed <= 104 ; speed++) {
        motors.setRightSpeed(speed);
        motors.setLeftSpeed(0);
        delay(angleDelay);
      }
      motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
    }
  }
  motors.setRightSpeed(0);
  motors.setLeftSpeed(0);
}
void ultrasonicReadFrontRightmm(){
  float duration; 
  pinMode(pingPinRight, OUTPUT);
  digitalWrite(pingPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinRight, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinRight, LOW);
  pinMode(pingPinRight, INPUT);
  duration = pulseIn(pingPinRight, HIGH);
  distFrontRightmm = microsecondsToMillimeters(duration);
  //cm = microsecondsToCentimeters(duration);
  delay(100);
}

int microsecondsToCentimeters(float microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
float microsecondsToMillimeters(float microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2*10;
}
void ultrasonicReadSidecm(){
  float duration; 
  pinMode(pingPinSide, OUTPUT);
  digitalWrite(pingPinSide, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinSide, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinSide, LOW);
  pinMode(pingPinSide, INPUT);
  duration = pulseIn(pingPinSide, HIGH);
  xPositioncm= microsecondsToCentimeters(duration);
  delay(100);
}
void ultrasonicReadFrontLeftmm(){
  float duration; 
  pinMode(pingPinLeft, OUTPUT);
  digitalWrite(pingPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinLeft, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinLeft, LOW);
  pinMode(pingPinLeft, INPUT);
  duration = pulseIn(pingPinLeft, HIGH);
  distFrontLeftmm = microsecondsToMillimeters(duration);
  //cm = microsecondsToCentimeters(duration);
  delay(100);
}
