#include <ZumoMotors.h>
#include <Ultrasonic.h>



ZumoMotors motors;
Ultrasonic ultrasonicR(0);
Ultrasonic ultrasonicL(1);
Ultrasonic ultrasonicSide(1,2);


unsigned long time;
bool doo = true;

#define echoPin 1 // Echo Pin
#define trigPin 0 // Trigger Pin
int pingPin = 6;

double duration, distance; // Duration used to calculate distance
int TheDifferent = 345;
double maxx = 67;
double target = 66.5;
double minn = 66;
int direction1 = 0;

double adjustMaxx = (maxx + 1);
double adjustMinn = (minn - 1);
boolean isTheRoboticInTheRightSpotStage_1 = false ;

double diff;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {


 // driveTheRoboticToStage_1();
Serial.println( ultrasonicSide.distanceRead());

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
    delay(4000);
  }
  // Get the distance and store it on the @distance
  distance = getSideDistance();
  // if the distance more than maximum distance or less than the minimum distance then call the method inside if statement.

  // if the distance less than the minimum distance then call turnLeft method
  if ( distance < minn  && time < 18000) { // turn to left.
    // calling the turnLeft method.
    // the turnLeft mathed take the current side distance.
    turnLeft(getSideDistance());
    // else if the distance more than the maximum distance then call turnRight method
  }   else if ( distance > maxx  && time < 18000) { // turn to right
    // calling the turnLeft method.
    // the turnLeft mathed take the current side distance.
    turnRight(getSideDistance());
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

  if (getSideDistance() > adjustMaxx ) {
    adjustRight();
    direction1 = 0;
    delay(200);

  } else if ( getSideDistance() < adjustMinn ) {
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
/* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */


double getSideDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);


  //Calculate the distance (in cm) based on the speed of sound.
  //  duration / 58.2;

  return (duration / 58.2) ;
}


boolean isTheRoboticInTheRightSpotMethod() {
  if (getFrontDuration() < TheDifferent) {
    return true;
  } else {
    return false;
  }
}


long getFrontDuration() {
  long duration;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // print
  Serial.print("Front Duration : ");
  Serial.println(duration);


  return duration ;
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
  motors.setLeftSpeed(80);
  motors.setRightSpeed(80);
  delay(700);
}
void AdjustAngle() {

  double R ;
  double L  ;

  Serial.print( R);
  Serial.print(" , ");
  Serial.print(L);
  Serial.print(" , ");
  Serial.println();


  while (doo) {
    R = ultrasonicR.distanceRead() ;
    delay (10);
    L = ultrasonicL.distanceRead() ;
    if (R < L) {
      motors.setLeftSpeed(100);
      motors.setRightSpeed(0);

    } else if (R > L) {
      motors.setLeftSpeed(0);
      motors.setRightSpeed(100);

    } else {

      doo = false;
      motors.setLeftSpeed(0);
      motors.setRightSpeed(0);
    }
  }
}
