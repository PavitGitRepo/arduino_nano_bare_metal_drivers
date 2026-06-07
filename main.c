/*
 * File:        main.ino
 * Project:     Mosture and Earthquack Monitoring Syatem
 * Description: [Will add later
 * Author:      Pavit Bhatia
 * Date:        31/08/2-25
 * Last Modified: Current
 *
 * Copyright (c) 2025 PTech Innovations. All rights reserved.
 * Licensed under the 1234567890 License. See LICENSE file for details.
 *
 * Revision History:
 * [YYYY-MM-DD] [Author]: Initial creation.
 * [YYYY-MM-DD] [Author]: [Description of change].
 */


#include "LiquidCrystal_I2C.h"
#include "Wire.h"
#include "moisture.h"
#include "vibration.h"

// Moisture Sensor Arduino Code
const unsigned int buzzer = 6;
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
      digitalWrite(buzzer, LOW);
  init_vib();
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Welcome Students");
  lcd.setCursor(0,1);
  lcd.print("~<------------>~");
  delay(3000);
}

void loop() {
  bool vib_status = false;
  lcd.clear();

//Reading and Printing Moisture Sensor-----
  int Moisture = readMoistureSensor();
  Serial.print("Moisture: ");Serial.println(Moisture);
  lcd.setCursor(0,1);lcd.print("Moisture: ");lcd.print(Moisture);lcd.print(" %");

//Reading and printing vibration sensor
  vib_status = read_vibration();
  if(vib_status)
  {
    digitalWrite(buzzer, HIGH);
    Serial.println("!!!Earthquack!!!");
    lcd.setCursor(0,0);lcd.println("!!!Earthquack!!!");
     delay(500);
  }
  else
  {
    Serial.println("*No *Earthquack*");
    lcd.setCursor(0,0);lcd.println("*No *Earthquack*");
  }
 
  if(Moisture >= 50)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    delay(250);
  }
}


