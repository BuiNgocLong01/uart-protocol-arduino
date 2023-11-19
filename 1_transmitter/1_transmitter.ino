int Button1 = 8;
const int sensorPin = A0; // Light sensor

void setup()
{
  Serial.begin(9600); // for communication

  pinMode(sensorPin, INPUT);
  pinMode(Button1, INPUT_PULLUP); // for read button
}

void loop()
{
  int value = analogRead(sensorPin);
//  Serial.println("Sensor Value: " + String(value));
//  delay(500);


    if (digitalRead(Button1) == 0)
    {
      Serial.write('1');
    }
  
    if (value < 300)
    {
      Serial.write('0');
    }
  
    else if (value >= 300 && value < 350)
    {
      Serial.write('1');
    }
  
    else if (value >= 350 && value < 450)
    {
      Serial.write('2');
    }
  
    else if (value >= 450)
    {
      Serial.write('3');
    }


  delay(20); // waitting message send
}
