
int RED_PIN = 12;
int YELLOW_PIN =11;
int GREEN_PIN = 10;
 

 

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}
 
void loop() {
   delay(1000);
  digitalWrite(RED_PIN, HIGH);
 delay(1000);
  digitalWrite(YELLOW_PIN, HIGH);
 delay(1000);
  digitalWrite(GREEN_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_PIN, LOW);
 delay(1000);
  digitalWrite(YELLOW_PIN, LOW);
 delay(1000);
  digitalWrite(GREEN_PIN, LOW);
  
  
  
}
