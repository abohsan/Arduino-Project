
#define RightRed_PIN 12
#define NothingYellow_PIN 11
#define LeftGreen_PIN 10

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(9600);               // starts the serial monitor

  pinMode(RightRed_PIN, OUTPUT);
  pinMode(NothingYellow_PIN, OUTPUT);
  pinMode(LeftGreen_PIN, OUTPUT);
}

void loop()
{
  val = analogRead(sensorpin);// reads the value of the sharp sensor
  Serial.println(val);
  if (val < 100  ||  val > 105.5 )
  {

    ////
if (val < 100) {

      digitalWrite(RightRed_PIN, HIGH);
      digitalWrite(NothingYellow_PIN, LOW);
      digitalWrite(LeftGreen_PIN, LOW);

    }   else if (val > 110) {
      digitalWrite(RightRed_PIN, LOW);
      digitalWrite(NothingYellow_PIN, LOW);
      digitalWrite(LeftGreen_PIN, HIGH);
    }


    ///

  } else   {
    digitalWrite(RightRed_PIN, LOW);


    digitalWrite(NothingYellow_PIN, HIGH);

    digitalWrite(LeftGreen_PIN, LOW);
  }
  delay(200);
}


