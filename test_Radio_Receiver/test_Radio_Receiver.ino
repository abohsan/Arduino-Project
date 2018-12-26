#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int RED_PIN = 9;
RF24 radio(7, 8);

const byte rxAddr[6] = "00001";

void setup()
{
  while (!Serial);
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
//  
  radio.startListening();
}

void loop()
{
   
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
     String myString = String(text);
    if (myString == "Hello World"){
      Serial.print("Hello World :");
      Serial.println(text);
      digitalWrite(RED_PIN, LOW);
    }
   
    if(myString == "Hello"){
       Serial.print("Hello :");
      Serial.println(text);
     
      digitalWrite(RED_PIN, HIGH);
    }
    
  }
}
