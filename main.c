/*
 * File:        main.c
 * Project:     Mosture and Earthquack Monitoring Syatem
 * Description: This is a small project for checking soil moisture for land slide detection and Earthquack Monitoring/warning
 * Author:      Pavit Kumar
 * Date:        31/08/2025
 * Last Modified: Current
 *
 * Copyright (c) 2025 PTech Innovations. All rights reserved.
 *
 * Revision History:
 * [2025-08-31] [Author]: Initial creation.
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


