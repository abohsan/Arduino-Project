#include <SoftwareSerial.h>

// software serial : TX = digital pin 10, RX = digital pin 11
SoftwareSerial mySerial(4, 5);


void setup()
{
  // Start the hardware serial port
  Serial.begin(9600);

  // Start both software serial ports
  mySerial.begin(9600);
  

}

void loop() {
  String message = myNextion.listen(); //check for message
  if (message != "") { // if a message is received...
    Serial.println(message); //...print it out
  }
  if (message == "65 0 2 0 ffff ffff ffff") {
    Serial.println("Pressed Checkbox 1!");
  }
}



  

