#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define gate 10

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x3F, 16, 2);  

void setup(){
  //Serial.begin(9600);
  lcd.backlight();
  lcd.init(); 

  pinMode(gate,OUTPUT);
  digitalWrite(gate,LOW);
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Enter field");
  lcd.setCursor(0,1);
  lcd.print("strength 1-9:");
  
  char customKey = customKeypad.getKey();
  int number = atoi(customKey);
  
  if (customKey){
    //Serial.println(customKey);
    lcd.clear();
    lcd.setCursor(14, 1); 
    lcd.print(customKey);
    switch (customKey){
      case '1':
        analogWrite(gate,0);
        break;
      case '2':
        analogWrite(gate,100);
        break;
      case '3':
        analogWrite(gate,130);
        break;
      case '4':
        analogWrite(gate,150);
        break;
      case '5':
        analogWrite(gate,170);
        break;
      case '6':
        analogWrite(gate,190);
        break;
      case '7':
        analogWrite(gate,210);
        break;
      case '8':
        analogWrite(gate,230);
        break;
      case '9':
        analogWrite(gate,255);
        break;
      default:
        break;
    }
  }
}
