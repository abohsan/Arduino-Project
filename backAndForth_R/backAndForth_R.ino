//#include <SPI.h>
//#include <nRF24L01.h>
#include <RF24.h>
int Green_PIN = 5;
int Yellow_PIN = 10;
int Red_PIN = 9;
RF24 radio(7, 8);
int x = 0;
const byte rxAddr[6] = "00001";

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  pinMode(Green_PIN, OUTPUT);
  pinMode(Red_PIN, OUTPUT);
  pinMode(Yellow_PIN, OUTPUT);
  radio.begin();
  radio.setRetries(15, 10);
  radio.openWritingPipe(rxAddr);
  radio.openReadingPipe(0, rxAddr);

  radio.startListening();

}

void loop()
{

  if (radio.available())
  {


    radio.stopListening();

    String myMessage = getNewMessage();

    Serial.println(myMessage);

    if (myMessage == "Green") {
      
     
    if (digitalRead(Green_PIN) == 1)
    {
      digitalWrite(Green_PIN, LOW);
//      send_1("YellowLow");
//      send_1("YellowLow");
    } else {
      digitalWrite(Green_PIN, HIGH);
//      send_1("YellowHigh");
//      send_1("YellowHigh");
    }
    
  } else if (myMessage == "Yellow") {


    if (digitalRead(Yellow_PIN) == 1)
    {
      digitalWrite(Yellow_PIN, LOW);
//      send_1("YellowLow");
//      send_1("YellowLow");
    } else {
      digitalWrite(Yellow_PIN, HIGH);
//      send_1("YellowHigh");
//      send_1("YellowHigh");
    }


  } else if (myMessage == "Red") {

    if (digitalRead(Red_PIN) == 1)
    {
      digitalWrite(Red_PIN, LOW);
//      send_1("RedLow");
//      send_1("RedLow");
    } else {
      digitalWrite(Red_PIN, HIGH);
//      send_1("RedHigh");
//      send_1("RedHigh");
    }
  }

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

  //Serial.println(textToBeSend);

  delay(1000);
}

String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

}

