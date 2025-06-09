#include "MQ135.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 7, 6, 5, 4);

const int ANALOGPIN = 0;
MQ135 gasSensor = MQ135(ANALOGPIN);

void setup() {

  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);

  lcd.begin(16, 2);
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(3000);
  lcd.clear();

}

void loop() {
  
  /*
  float rzero = gasSensor.getRZero();
  lcd.setCursor(0, 0);
  lcd.print("R0: ");
  lcd.print(rzero);
  */

  float ppm = gasSensor.getPPM();
  lcd.setCursor(0, 0);
  lcd.print("CO2 PPM: ");
  lcd.print(ppm);

  if(ppm <= 1100){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Clean Air");
  }else{
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Dirty Air");
  }

  delay(1000);
  lcd.clear();

}
