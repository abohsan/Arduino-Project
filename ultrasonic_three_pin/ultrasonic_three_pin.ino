int pingPin = 6;

void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
}

void loop()
{
  getFrontDuration();

  delay(100);
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

