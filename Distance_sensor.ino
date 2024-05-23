#include <Wire.h>

#include <LiquidCrystal_I2C.h> 

// Set the LCD address.

//if you don't know what is your lcd address.

//just upload lcd I2C address Finder code and check the serial moniter.

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = 3;

const int echo = 4;

int duration = 0;

int distance = 0;

int i;

void setup()

{

  //ultrasonic sensor

  pinMode(trig , OUTPUT);

  pinMode(echo , INPUT);

  //LEDS

  for (i = 5; i <= 13; i++) {

    pinMode(i, OUTPUT);

  }

  //LCD display

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

  digitalWrite(trig , HIGH);

  delayMicroseconds(1000);

  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);

  distance = (duration / 2) / 29.1 ;


  Serial.println(distance);


  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Distance: "); 

  lcd.print(distance);

  lcd.print("CM"); 

  delay(500);


  // ROSU

  if (distance >= 18 && distance < 25) { 
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
  } else { 
    digitalWrite(5, LOW); 
  }

  if (distance >= 10 && distance < 18) { 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, LOW); 

    } else { 
      digitalWrite(5, LOW); 
      digitalWrite(6, LOW); 
      digitalWrite(7, HIGH); 
  }

    if (distance >= 1 && distance < 10) { 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  } else { 
    digitalWrite(7, LOW);  
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
  }

  // GALBEN


  // if (distance >= 21 && distance < 30) { 
  //   digitalWrite(8, HIGH);
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 
  // } else { 
  //   digitalWrite(8, LOW); 
  // }

  // if (distance >= 24 && distance < 30) { 
  //   digitalWrite(9, HIGH);
  //   digitalWrite(8, HIGH); 
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 
  // } else { 
  //   digitalWrite(9, LOW); 
  // }

  // if (distance >= 27 && distance < 30) { 
  //   digitalWrite(10, HIGH); 
  //   digitalWrite(9, HIGH); 
  //   digitalWrite(8, HIGH); 
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 
  // } else { 
  //   digitalWrite(10, LOW); 
  // }

  // // VERDE 


  // if (distance >= 30) { 
  //   digitalWrite(11, HIGH); 
  //   digitalWrite(10, LOW); 
  //   digitalWrite(9, LOW); 
  //   digitalWrite(8, LOW); 
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 

  // } else { 
  //   digitalWrite(11, LOW); 
  // }

  // if (distance >= 33) { 
  //   digitalWrite(12, HIGH); 
  //   digitalWrite(10, LOW); 
  //   digitalWrite(9, LOW); 
  //   digitalWrite(8, LOW); 
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 
  // } else { 
  //   digitalWrite(12, LOW); 
  // }

  // if (distance >= 36) { 
  //   digitalWrite(13, HIGH); 
  //   digitalWrite(10, LOW); 
  //   digitalWrite(9, LOW); 
  //   digitalWrite(8, LOW); 
  //   digitalWrite(7, LOW);  
  //   digitalWrite(6, LOW); 
  //   digitalWrite(5, LOW); 
  // } else { 
  //   digitalWrite(13, LOW); 
  // }

  //   if (distance >= 10) { digitalWrite(13, HIGH); } else { digitalWrite(13, LOW); }
  // if (distance >= 13) { digitalWrite(12, HIGH); } else { digitalWrite(12, LOW); }
  // if (distance >= 15) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
  // if (distance >= 18) { digitalWrite(10, HIGH); } else { digitalWrite(10, LOW); }
  // if (distance >= 21) { digitalWrite(9, HIGH); } else { digitalWrite(9, LOW); }
  // if (distance >= 24) { digitalWrite(8, HIGH); } else { digitalWrite(8, LOW); }
  // if (distance >= 27) { digitalWrite(7, HIGH); } else { digitalWrite(7, LOW); }
  // if (distance >= 30) { digitalWrite(6, HIGH); } else { digitalWrite(6, LOW); }
  // if (distance >= 33) { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); }
  // if (distance >= 36) { digitalWrite(4, HIGH); } else { digitalWrite(4, LOW); }

}