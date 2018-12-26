#include <ZumoMotors.h>
#include <ZumoBuzzer.h>


ZumoBuzzer buzzer;
ZumoMotors motors;
unsigned long time;


#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin

double duration, distance; // Duration used to calculate distance

double maxx = 67;
double target = 66.5;
double minn = 66;
int direction1 = 0;

double adjustMaxx = (maxx + 1);
double adjustMinn = (minn - 1);

boolean safetyStep = true ;

double diff;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motors.setLeftSpeed(50);
  motors.setRightSpeed(50);
}


void loop() {

  /*
        delay to allow the robotic to skip the box before it depends on Ultrasonic Sensor.
        The delay time may change relativaly to the robotic speed.
  */
  delay(300);
  time = millis();
  Serial.println(time);
  if (time < 3000){
    delay(4000);
    
    buzzer.playNote(NOTE_A(4), 200, 9);
    delay(300);
    buzzer.playNote(NOTE_A(4), 200, 9);
  }


  // Get the distance and store it on the @distance
  distance = getDistance();

  // if the distance more or less than the limit distance then call the method inside if statement.
  if ( (distance > maxx || distance < minn ) && !safetyStep) {
//&& time < 13000
    // if the distance less than the minimum distance then call turnLeft method
    if ( distance < minn ) { // turn to left.

      // calling the turnLeft method.
      turnLeft(getDistance());


      // else if the distance more than the maximum distance then call turnRight method
    }   else if ( distance > maxx ) { // turn to right

      // calling the turnLeft method.
      turnRight(getDistance());
    }


    // the safetyStep is false by default 
    // 
  } else if (!safetyStep && time < 13000) {
    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
    buzzer.playNote(NOTE_A(2), 200, 10);

  }


if (time > 14000){
  safetyStep = true;
  buzzer.playNote(NOTE_A(4), 200, 9);
  delay(200);
  buzzer.playNote(NOTE_A(4), 200, 9);

  motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
}


  // adjust

//  if (safetyStep) {
//
//    if (getDistance() > adjustMaxx ) {
//      adjustRight();
//      direction1 = 0;
//      delay(200);
//
//    } else if ( getDistance() < adjustMinn ) {
//
//      adjustLeft();
//      direction1 = 1;
//      delay(200);
//    } else {
//
//
//      if (direction1 == 0) {
//        adjustRight() ;
//        delay(200);
//      } else if (direction1 == 1) {
//        adjustLeft();
//        delay(200);
//
//      }
//
//    }
//
//  }

}


/* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */


double getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);


  //Calculate the distance (in cm) based on the speed of sound.
  //  duration / 58.2;

  Serial.println((duration / 58.2 ));

  return (duration / 58.2) ;
}

void turnLeft(double dis) {
  motors.setLeftSpeed(20);
  motors.setRightSpeed(50);
}

void turnRight(double dis) {
  motors.setLeftSpeed(50);
  motors.setRightSpeed(20);
}

void adjustRight() {

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(0);
  delay(300);

  motors.setLeftSpeed(-100);
  motors.setRightSpeed(-60);
  delay(400);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(-100);
  delay(300);
  motors.setLeftSpeed(100);
  motors.setRightSpeed(100);
  delay(800);
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
  motors.setLeftSpeed(100);
  motors.setRightSpeed(100);
  delay(800);
}
