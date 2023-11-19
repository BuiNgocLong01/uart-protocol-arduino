#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

const int ledPin1 = 4;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  // Receive Data
  if (mySerial.available() > 0) 
  {
    char receivedChar = mySerial.read();

    if (receivedChar == '1')
    {
      digitalWrite(ledPin1, HIGH);
      Serial.println("Da Nhan Du lieu tu Arduino 1 !");
      mySerial.println("2 Recevived !");
    }
    delay(20);
    digitalWrite(ledPin1, LOW);
  }
}
