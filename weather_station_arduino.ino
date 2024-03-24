#include <SoftwareSerial.h>

SoftwareSerial mySerial (4, 5); //4 --> TX 5 --> RX

void setup(){
Serial.begin(9600);
mySerial.begin(9600);
}

void loop(){
int myValue = analogRead(A0);
myValue = myValue * 0.488281125;
Serial.println(myValue);

int ch = 0x3FB + myValue;
byte checkSum = ch;
checkSum = 0xFF - checkSum;

byte data[] = {0x7E, 0x00, 0x0F, 0x10, 0x01, 0x00, 0x13, 0xA2, 0x00, 0x41, 0x9B, 0x54, 0x08, 0xFF, 0xFE, 0x00, myValue, checkSum};
mySerial.write(data, 19);
delay(3500);
}


