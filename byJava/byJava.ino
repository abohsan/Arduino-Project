
int RED_PIN = 12;
int YELLOW_PIN =11;
int GREEN_PIN = 10;
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  int text1 = Serial.read();
  Serial.println(text1);
  String text = Serial.readString();

  if (text == "R0") {
    digitalWrite(RED_PIN, LOW);
    text = "";

  }
   if (text == "R1") {
    digitalWrite(RED_PIN, HIGH);
    text = "";

  }
   if (text == "Y0") {
    digitalWrite(YELLOW_PIN, LOW);
    text = "";

  }
   if (text == "Y1") {
    digitalWrite(YELLOW_PIN, HIGH);
    text = "";

  }
   if (text == "G0") {
    digitalWrite(GREEN_PIN, LOW);
    text = "";

  }
   if (text == "G1") {
    digitalWrite(GREEN_PIN, HIGH);
    text = "";

  }
}
