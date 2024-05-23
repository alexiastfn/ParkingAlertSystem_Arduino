#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trig = 3;
const int echo = 4;
const int buzzer = 2;

const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;

const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 8;

const int LED7 = 7;
const int LED8 = 6;
const int LED9 = 5;

int duration = 0;
int distance = 0;

unsigned long previousMillis = 0;
unsigned long interval = 500; // ntervalul pentru intreruperea sunetului în milisec
bool buzzerState = false;

unsigned long intervalBlink = 250;
bool blinkState = false;
unsigned long previousMillisBuzzer = 0;
unsigned long previousMillisBlink = 0;

void setup()
{
  // Ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);

  lcd.begin();
  delay(100);

  lcd.backlight();
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Initializare...");
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;
  Serial.println(distance);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(200);

  unsigned long currentMillis = millis();

  // ajustez intervalul in fct de dist
  if (distance <= 4) {
    interval = 100; // distance <= 4 cm
  } else if (distance <= 8) {
    interval = 200; // distance <= 8 cm
  } else if (distance <= 14) {
    interval = 300; // distance <= 14 cm
  } else {
    interval = 500; // default 
  }

  // Buzzer logic pentru dist <= 14 cm
  if (distance <= 14)
  {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      buzzerState = !buzzerState;
      if (buzzerState) {
        if (distance <= 4) {
          tone(buzzer, 1000);
        } else if (distance <= 8) {
          tone(buzzer, 900);
        } else {
          tone(buzzer, 800);
        }
      } else {
        noTone(buzzer);
      }
    }
  }
  else
  {
    noTone(buzzer);
  }


  // ROSU
  if (distance <= 4)
  {
    digitalWrite(LED9, HIGH);

    if (distance <= 4 && digitalRead(LED7) == HIGH && digitalRead(LED8) == HIGH && digitalRead(LED9) == HIGH) {
      if (currentMillis - previousMillisBlink >= intervalBlink) {
          previousMillisBlink = currentMillis;
          blinkState = !blinkState;
          digitalWrite(LED7, blinkState ? LOW : HIGH);
          digitalWrite(LED8, blinkState ? LOW : HIGH);
          digitalWrite(LED9, blinkState ? LOW : HIGH);
          delay(175);
      }
  }
} else {
    digitalWrite(LED9, LOW);
  }

  if (distance <= 8)
  {
    digitalWrite(LED8, HIGH);
  }
  else
  {
    digitalWrite(LED8, LOW);
  }

  if (distance <= 14)
  {
    digitalWrite(LED7, HIGH);
  }
  else
  {
    digitalWrite(LED7, LOW);
  }


  // GALBEN
  if (distance <= 16 && distance >= 15)
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }

  if (distance <= 19 && distance >= 15)
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }

  if (distance <= 21 && distance >= 15)
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }

  // VERDE
  if (distance >= 22)
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }

  if (distance >= 26)
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }

  if (distance >= 29)
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
}
