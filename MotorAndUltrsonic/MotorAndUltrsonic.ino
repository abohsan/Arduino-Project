#include <ZumoMotors.h>

ZumoMotors motors;


#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin

double duration, distance; // Duration used to calculate distance
double maxx = 20.0;
double target = 19.98;
double minn = 19.96;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motors.setLeftSpeed(50);
  motors.setRightSpeed(50);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);


  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;
  Serial.println(distance);
  if (distance > maxx || distance < minn) {

    if (distance < minn) { // turn to left.

      motors.setLeftSpeed(40);
      motors.setRightSpeed(60);

    }   else if (distance > maxx) { // turn to right

      motors.setLeftSpeed(60);
      motors.setRightSpeed(40);

    }


  }
  else {
    motors.setLeftSpeed(50);
    motors.setRightSpeed(50);

  }

  //Delay 50ms before next reading.
  delay(50);
}
