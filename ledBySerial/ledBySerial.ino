#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
int yel = 3;
int gre = 4;

const byte rxAddr[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);

  pinMode(OUTPUT, yel);
  pinMode(OUTPUT, gre);
  radio.stopListening();

}
void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    String mass = Serial.readString();
    send_1(mass) ;
  

  }
}


void send_1(String textToBeSend) {
  int i = 0;
  char textS[textToBeSend.length()] ;
  while (i < textToBeSend.length()) {
    textS[i] = textToBeSend.charAt(i);
    i++;
  }
  radio.write(&textS, sizeof(textS));
  delay(1000);
}
