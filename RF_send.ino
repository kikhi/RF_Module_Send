#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (9, 10);
byte addresses[][6] = {"0"};

struct package {
  int id=1;
  char  text[300] = "Text to be transmit";
  int punto = Serial.println(analogRead(A1));
};


typedef struct package Package;
Package data;


void setup() {
  Serial.begin(115200);
  delay(1000);

  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  myRadio.openWritingPipe(addresses[0]);

  
}

void loop() {
  myRadio.write(&data, sizeof(data)); 
  Serial.print("\nPackage:");
  Serial.print(data.id);
  Serial.print("\n");
  data.punto = Serial.print(analogRead(A1));
  
  delay(100);
}
