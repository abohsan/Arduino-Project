int i;
void setup() {
  int i = 0 ;
  Serial.begin(9600);

}

void loop() {
  
  delay(500);
   i = (i + 1);
   Serial.println(i);
//  //Serial.write(i);
//  //Serial.write(i +"LEAD IS LOW\n");
//  delay(1000);
//

}
