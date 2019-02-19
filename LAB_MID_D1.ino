//Tanvir Hossain
//ID: 16.01.05.170
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
byte lupTable[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void setup() {
  DDRD = 0xFF;
  DDRB = 0xFF;
  lcd.init();
  lcd.backlight();
  }

void loop() {
  for(int i=0;i <=3; i++){
      lcd.setCursor(i,0);
      lcd.print("8");
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      
      delay(1000);
      lcd.clear();
      
      PORTD = lupTable[8];
      PORTB = 0b111111;
      bitClear(PORTB,i);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      delay(1000);
      bitWrite(PORTB,i,1);
  }

}
