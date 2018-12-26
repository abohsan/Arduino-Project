#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int RED_PIN = 9;
RF24 radio(7, 8);
int x = 0;
const byte rxAddr[6] = "00001";

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
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
    Serial.print("I get new message " );
    Serial.println(myMessage);


    radio.startListening();
  }




}

String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

}

