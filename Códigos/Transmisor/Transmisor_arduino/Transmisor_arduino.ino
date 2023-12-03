#include "Wire.h"
# include "LiquidCrystal.h"  //lcd libary                                       
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD object Parameters: (rs, enable, d4, d5, d6, d7)
float voltaje; //trig pin connection 
float pot=1;
float Nivelcm;
void setup() {
  lcd.begin(16,2);  
  Serial.begin(9600);

}

void loop() {
  pot=analogRead(A0);
  
  voltaje = (pot / 1023.0) * 3.3; // Convierte la lectura a voltaje (0-3.3V)
  Nivelcm = (voltaje / 3.3) * 200.0; // Convierte el voltaje a nivel (0-300 cm)
  
/*
voltaje = map(pot, 0, 1023, 0, 3300);
Nivelcm = map(voltaje, 0, 3300, 0, 300);
  */
  lcd.setCursor(0, 0);
  lcd.print("Vol=");
  lcd.print(voltaje,2); // Muestra el voltaje con 2 decimales
  lcd.print(" V ");
  lcd.setCursor(0, 1);
  lcd.print("Nivel=");
  lcd.print(Nivelcm,2); // Muestra el nivel con 2 decimales
  lcd.print(" cm");

  Serial.print(voltaje,2); // Imprime el voltaje con 2 decimales
   Serial.print(",");
  Serial.print(Nivelcm,2); // Imprime el nivel con 2 decimales
    Serial.println();

  delay(10);
  /*
  Voltaje = (pot / 1023.0) * 3.3; // Convierte la lectura a voltaje (0-3.3V)
  Nivelcm = (Voltaje / 3.3) * 300.0; // Convierte el voltaje a nivel (0-300 cm)

  lcd.setCursor(0, 0);
  lcd.print("Vol=");
  lcd.print(Voltaje, 2); // Muestra el voltaje con 2 decimales
  lcd.print(" V ");
  lcd.setCursor(0, 1);
  lcd.print("Nivel=");
  lcd.print(Nivelcm, 2); // Muestra el nivel con 2 decimales
  lcd.print(" cm");

  Serial.print("Voltaje: ");
  Serial.println(Voltaje, 2); // Imprime el voltaje con 2 decimales
  Serial.print("Nivel (cm): ");
  Serial.println(Nivelcm, 2); // Imprime el nivel con 2 decimales
  delay(10);
   */
}