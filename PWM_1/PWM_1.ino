
int a = 10;
int c = 7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  //pinMode(c, INPUT);
  analogWrite(a,260 );
}

void loop() {
//  // put your main code here, to run repeatedly:
//  if (Serial.available() > 0) {
//   // int b = Serial.read();
//    Serial.println(Serial.read());
//    //analogWrite(a, b);
//  }

//Serial.println(analogRead(A0)/4);
analogWrite(a, analogRead(A0)/4);

}
