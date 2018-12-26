
#define RightRed_PIN 12
#define NothingYellow_PIN 11
#define LeftGreen_PIN 10
#define LED_PIN 13

#include <ZumoMotors.h>

ZumoMotors motors;

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
double val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(9600);               // starts the serial monitor

  pinMode(RightRed_PIN, OUTPUT);
  pinMode(NothingYellow_PIN, OUTPUT);
  pinMode(LeftGreen_PIN, OUTPUT);
}

void loop()
{
   motors.setLeftSpeed(50);
   motors.setRightSpeed(50);
  val = analogRead(sensorpin);// reads the value of the sharp sensor
  Serial.println(val);
  if (val < 67.5  ||  val > 68.5 )  // Do something
  {

    ////
    if (val < 67.5) { // turn to left.

  
     motors.setLeftSpeed(40);
    motors.setRightSpeed(60);
  //    digitalWrite(RightRed_PIN, HIGH);
   //   digitalWrite(NothingYellow_PIN, LOW);
   //   digitalWrite(LeftGreen_PIN, LOW);

    }   else if (val >68.5) { // turn to right

      motors.setLeftSpeed(60);
    motors.setRightSpeed(40);
     // digitalWrite(RightRed_PIN, LOW);
     // digitalWrite(NothingYellow_PIN, LOW);
     // digitalWrite(LeftGreen_PIN, HIGH);
    }


    ///

  } else   { 
    // Do nothing 

      motors.setLeftSpeed(50);
    motors.setRightSpeed(50);
    // turn off the moter
   // digitalWrite(RightRed_PIN, LOW);
  //  digitalWrite(NothingYellow_PIN, HIGH);
   // digitalWrite(LeftGreen_PIN, LOW);
  }
  delay(300);
}


