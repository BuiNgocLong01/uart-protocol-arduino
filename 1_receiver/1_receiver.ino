const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Receive Data
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();

    if (receivedChar == '1')
    {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }

    if (receivedChar == '2')
    {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
    }

    if (receivedChar == '3')
    {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
    }

    if (receivedChar == '0')
    {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }
    delay(20);
  }
}
