#define BLYNK_TEMPLATE_ID "TMPL2_qYThxwl"
#define BLYNK_TEMPLATE_NAME "Proyecto"
#define BLYNK_AUTH_TOKEN "n3N8hoIhRc0o2uh9yoYxnMU1baaBp8PG"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

float corriente = 8.8; // Corriente medida
int Nivelcm=20;

char ssid[] = "Marte";
char pass[] = "1005332914";

void func(){
  Serial.print("Corriente: ");
  Serial.print(corriente);
  Serial.print('\n');
  Serial.print("Nivel: ");
  Serial.print(Nivelcm);
  Serial.print('\n');
  Blynk.virtualWrite(V5, corriente);
  Blynk.virtualWrite(V6, Nivelcm);
}
void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // put your setup code here, to run once:

}

void loop() {
  func();
  Blynk.run();
  // put your main code here, to run repeatedly:

}
