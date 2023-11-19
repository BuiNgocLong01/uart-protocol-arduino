/*
 * Author: Long Bui Ngoc
 * Arduino 1: Transmit
 * Using SoftwareSerial library
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int Button1 = 4;

void setup()
{
  Serial.begin(9600); // for communication
  mySerial.begin(9600);

  pinMode(Button1, INPUT_PULLUP); // for read button
}

void loop()
{

  if (digitalRead(Button1) == 0)
  {
    mySerial.write('1');
  }

  if (mySerial.available() > 0)
  {
    String dataReceived = mySerial.readStringUntil('\n');
    Serial.println("Phan hoi tu Arduino 2: " + dataReceived);
  }

    delay(20); // waitting message send
  }
