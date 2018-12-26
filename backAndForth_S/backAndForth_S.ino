//#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);
unsigned long time;
boolean isReplay = false;

int x = 0;
const byte rxAddr[6] = "00002";

void setup()
{
  while (!Serial);
  Serial.begin(9600);

  radio.begin();
  radio.setRetries(10, 15);
  radio.openWritingPipe(rxAddr);
  radio.openReadingPipe(0, rxAddr);
  radio.stopListening();
  //radio.startListening();
  Serial.println("Ready !");
}

void loop()
{


  if (Serial.available()) {
   
    send_1(Serial.readString());
  
    checkListening1();
  }
  

}

//void checkListening() {
//  radio.startListening();
//  time = millis() + 200;
//  while (time > millis()) {
//
//    if (radio.available() ) {
//
//      Serial.println(getNewMessage());
//     isReplay= true;
//
//    }
//
//  }
//
//  radio.stopListening();
//}
void checkListening1() {
  radio.startListening();
  time = millis() + 500;
  
  while (time > millis() && !isReplay) {

    if (radio.available() ) {
      Serial.println(getNewMessage());
      isReplay = true;
    }

  }


  if (!isReplay) {
    Serial.println("No Respones");

  }else{
    Serial.println("There is Respones");
    isReplay = false;
  }

  
  radio.stopListening();
}

void send_1(String textToBeSend) {

  int i = 0;
  char textS[textToBeSend.length()] ;

  while (i < textToBeSend.length()) {
    textS[i] = textToBeSend.charAt(i);
    i++;
  }

  radio.write(&textS, sizeof(textS));

  //Serial.println(textToBeSend);

  delay(1000);
}


String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

}

