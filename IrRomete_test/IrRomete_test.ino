#include <IRremote.h>

int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
     
    int num = results.value;
    Serial.println(num, BIN);
    uint8_t bitsCount = sizeof( num ) * 8;
    char str[ bitsCount + 1 ];
    itoa( num, str, 2 );
    int a = sizeof(str);
    for (int i = 0; i < a ; i++) {
      Serial.println( str[i] );
    }
    ; // Receive the next value
  }
  irrecv.resume();

  delay(100);
}
