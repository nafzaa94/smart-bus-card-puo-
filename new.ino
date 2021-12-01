// FOR ARDUINO MEGA

#include <SPI.h>
#include <MFRC522.h>
constexpr uint8_t RST_PIN = 9;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 10;     // Configurable, see typical pin layout above
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
String tag;

//library for servo
#include <Servo.h>
Servo myservo;

//library for lcd
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin1 = 2;
int pin2 = 3;

int buzz = 5;
int ledred = 22;
int ledgreen = 24;

int var = 0;

int count = 0;

int state1 = 0;
int state2 = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  myservo.attach(6);
  myservo.write(0);

  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  pinMode (buzz, OUTPUT);
  pinMode (ledred, OUTPUT);
  pinMode (ledgreen, OUTPUT);
}

void loop() {

  switch (var) {
  case 0:
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 4);
    lcd.print("WELCOME");
    var = 1;
    break;
  case 1:
    if ( ! rfid.PICC_IsNewCardPresent())
    return;
    if (rfid.PICC_ReadCardSerial()) {
      for (byte i = 0; i < 4; i++) {
        tag += rfid.uid.uidByte[i];
      }
      Serial.println(tag);
      var = 2;
    }
    break;
  case 2:
    if (tag == "8319420126" && state1 == 0){
    count++;
    lcd.setCursor(0, 1);
    lcd.print("COUNT = ");
    lcd.setCursor(8, 1);
    lcd.print(count);
    digitalWrite(ledgreen, HIGH);
    myservo.write(180);
    delay(3000);
    myservo.write(0);
    digitalWrite(ledgreen, LOW);
    digitalWrite (pin1, HIGH);
    delay (500);
    tag = "";
    state1 = 1;
    var = 3;
    }

    if (tag == "8319420126" && state1 == 1){
    count--;
    lcd.setCursor(0, 1);
    lcd.print("COUNT = ");
    lcd.setCursor(8, 1);
    lcd.print(count);
    digitalWrite(ledgreen, HIGH);
    myservo.write(180);
    delay(3000);
    myservo.write(0);
    digitalWrite(ledgreen, LOW);
    digitalWrite (pin1, HIGH);
    delay (500);
    tag = "";
    state1 = 0;
    var = 3;
    }

    if (tag == "13116319226" && state2 == 0){
      count++;
      lcd.setCursor(0, 1);
      lcd.print("COUNT = ");
      lcd.setCursor(8, 1);
      lcd.print(count);
      digitalWrite(ledgreen, HIGH);
      myservo.write(180);
      delay(3000);
      myservo.write(0);
      digitalWrite(ledgreen, LOW);
      digitalWrite (pin2, HIGH);
      delay (500);
      tag = "";
      state2 = 1;
      var = 3;
      }

    if (tag == "13116319226" && state2 == 1){
      count--;
      lcd.setCursor(0, 1);
      lcd.print("COUNT = ");
      lcd.setCursor(8, 1);
      lcd.print(count);
      digitalWrite(ledgreen, HIGH);
      myservo.write(180);
      delay(3000);
      myservo.write(0);
      digitalWrite(ledgreen, LOW);
      digitalWrite (pin2, HIGH);
      delay (500);
      tag = "";
      state2 = 0;
      var = 3;
      }
  
    if (tag == "154466437"){
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(3, 0);
      lcd.print("WRONG BUS");
      digitalWrite(buzz, HIGH);
      digitalWrite(ledred, HIGH);
      delay(2000);
      digitalWrite(buzz, LOW);
      digitalWrite(ledred, LOW);
      var = 3;
      } 
    break;
    case 3:
    if (tag == ""){
      digitalWrite (pin1, LOW);
      digitalWrite (pin2, LOW);
      }

    var = 0;
    break;
  }
  
}   
  
