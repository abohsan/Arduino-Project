#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int yel = 3;
int gre = 4;
RF24 radio(7, 8);
int x = 0;
const byte rxAddr[6] = "00001";

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.openReadingPipe(0, rxAddr);
  //
  radio.startListening();
}

void loop()
{

  if (radio.available())
  {
    radio.stopListening();
    String myMessage = getNewMessage();

    Serial.println(myMessage);
    turnONorOFF(myMessage);
    radio.startListening();
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
void turnONorOFF(String d) {
  if (d == "gn") {
    digitalWrite(gre, HIGH);
  } else if (d == "gf") {
    digitalWrite(gre, LOW);
  } else if (d == "yn") {
    digitalWrite(yel, HIGH);
  } else if (d == "yf") {
    digitalWrite(yel, LOW);
  }

}
String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

}

