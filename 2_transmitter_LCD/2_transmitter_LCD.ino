int Button1 = 13;
int Button2 = 12;
//Sender Arduino Board Code (Master)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // for communication

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("UART TRANSMITTER...");
  delay(1000);

  pinMode(Button1, INPUT_PULLUP); // for read button
  pinMode(Button2, INPUT_PULLUP); // for read button

}

void loop()
{


  if (digitalRead(Button1) == 0)
  {
    Serial.write('1');
    lcd.setCursor(0, 1); lcd.print("Da Gui 1 ...");
  }
  else if (digitalRead(Button2) == 0)
  {
    Serial.write('2');
    lcd.setCursor(0, 1); lcd.print("Da Gui 2 ...");
  }
  delay(20); // waitting message send
}
