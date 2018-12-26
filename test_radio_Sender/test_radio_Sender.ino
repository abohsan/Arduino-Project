#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
int x = 0;
const byte rxAddr[6] = "00001";

void setup()
{
Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);

  radio.stopListening();
}

void loop()
{
   
  if (x == 0) {
    char text[] = "Hello World";
    radio.write(&text, sizeof(text));
    x = 1;
    Serial.println("Send Hello World");
  } else {
    char text[] = "Hello";
    radio.write(&text, sizeof(text));
    x = 0;
       Serial.println("Send Hello");
  
  }

  delay(1000);
}
