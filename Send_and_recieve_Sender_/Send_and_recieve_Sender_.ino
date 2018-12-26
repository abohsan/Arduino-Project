
//This works fine along with Receive_and_send_Receiver_


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);

int x = 0;
int x1 = 0;
String cc = "";
const byte rxAddr[6] = "00001";

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  
  
 //  --------- Sender ------- 
  
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.openReadingPipe(0, rxAddr);
  radio.stopListening();
 
 // ---------- Reciever -----------


  
  
  

 
  

  Serial.println("Ready !");
}

void loop()
{


//  if (Serial.available()) {
// 
//    send_1(Serial.readString());
//   
//  }
x1++;
 cc = x1;
send_1(cc);
delay(1000);

Serial.println(cc);

}

void send_1(String textToBeSent) {

  int i = 0;
  char textS[textToBeSent.length()] ;

  while (i < textToBeSent.length()) {
    textS[i] = textToBeSent.charAt(i);
    i++;
  }
  
  radio.write(&textS, sizeof(textS));

  Serial.println(textToBeSent);
  
  delay(1000);
}

String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

}

