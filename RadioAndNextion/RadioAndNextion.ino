#include <RF24.h>


RF24 radio(7, 8);
unsigned long time;
boolean isReplay = false;

int x = 0;
const byte rxAddr[6] = "00001";

//---------
int dd = 0x05;
int char11, page, idd, ds;
int charflage = 0;
int stepp = 0 ;
String n0 = "n0.val=";
int ddd = 5 ;

void setup() {
  Serial.begin(9600);


  radio.begin();
  radio.setRetries(10, 15);
  radio.openWritingPipe(rxAddr);
  radio.openReadingPipe(0, rxAddr);
  radio.stopListening();
}

void loop() {

  if (Serial.available() > 1)
  {
    if (stepp == 1) {
      page =  Serial.read();
      delay(10);
      idd =  Serial.read();

      if (page == 0) {
        page0(idd);
      } else if (page == 1) {
        page1(idd);
      } else if (page == 2) {
        // page2(idd);
      }


      stepp = 0;
    } else {
      char11 = Serial.read();
      if (char11 == 0x65) {
        stepp = 1;
      }
    }

  }
}


void page0(int id) {

  if (id == 0) {
    send_1("OFF");
    Serial.println("OFF");
  } if (id == 1) {
    send_1("N");
    Serial.println("N");

  } if (id == 2) {
    send_1("ON");
    Serial.println("ON");

  }

}
void page1(int id) {

  if (id == 2) {
    send_1("Green");
    
  } if (id == 3) {
    send_1("Yellow");
    
  } if (id == 4) {
    send_1("Red");
    
  }

}
String getNewMessage() {

  char textR[32] = {0};
  radio.read(&textR, sizeof(textR));
  return String(textR);

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

