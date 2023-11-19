int LED1 = 13;
int LED2 = 12;
char message;

//Sender Arduino Board Code (Slave)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  Serial.begin(9600); // communication

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("UART RECEIVER...");
  delay(1000);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop()
{
  if (Serial.available())
  {
    message = Serial.read();
    if (message == '1')
    {
      digitalWrite(LED1, 1);
      lcd.setCursor(0, 1); lcd.print("Den 1 bat ...");
    }
    else if (message == '2')
    {
      digitalWrite(LED2, 1);
      lcd.setCursor(0, 1); lcd.print("Den 2 bat ...");
    }
  }
  else
  {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    lcd.setCursor(0, 1); lcd.print("Den Tat ...");
  }

  delay(20);
}
