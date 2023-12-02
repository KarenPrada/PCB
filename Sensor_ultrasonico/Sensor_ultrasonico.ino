# include "LiquidCrystal.h"  //lcd libary                                       
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   //LCD object Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 12; //trig pin connection 
const int echoPin = 11;  //echopin connection 
long duration;
int Nivelcm;
float liquid;
                                                                                                         
void setup() {      // setup perameter
lcd.begin(16,2);                                                   
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {   // loop of flow program
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
Nivelcm= duration*0.0092307692/2;                                                                                 
lcd.setCursor(0,0);                                                 
lcd.print("Nivel de agua");
delay(10);
lcd.setCursor(0,1);
lcd.print("Medida:");
lcd.print(Nivelcm);
lcd.print(" cm ");
delay(10);
}