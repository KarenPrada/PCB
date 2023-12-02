#define uS_TO_S_FACTOR 1000000  //Para convertir los microsegundos a segundos
#define TIME_TO_SLEEP 10 //IMPORTANTE: CAMBIAR A MEDIA HORA PARA ENVIAR LOS DATOS
//Blynk
#define BLYNK_TEMPLATE_ID "TMPL2_qYThxwl"
#define BLYNK_TEMPLATE_NAME "Proyecto"
#define BLYNK_AUTH_TOKEN "n3N8hoIhRc0o2uh9yoYxnMU1baaBp8PG"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//Variable que se guarda cuando se duerme la ESP32
//RTC_DATA_ATTR int bootCount = 0; 
//Credenciales de la red WiFi a conectar
char ssid[] = "Marte";
char pass[] = "1005332914";
//Timer de la libreria de Blynk
BlynkTimer timer; //Para mandar datos periódicamente
int datos_a_enviar = 20;
int datos_enviados = 0;
//Variables a sensar 
float Nivelcm = 1;
float voltaje = 1;
//Para separar la corriente del voltaje 
int delimitador;
String datos_leidos;
String dato1;
String dato2;

// Indicar que la ESP32 está conectada a la aplicación
//BLYNK_CONNECTED() {Blynk.virtualWrite(V0,1);}
//Enviar datos periódicamente
void myTimerEvent()
{
 // Blynk.virtualWrite(V4, bootCount); 

  if(Serial.available() != 0){

    datos_leidos = Serial.readStringUntil('\n');  // Lee los datos del puerto serial hasta el salto de línea
    delimitador = datos_leidos.indexOf(',');  // Busca el índice del delimitador

    if (delimitador != -1) {
      dato1 = datos_leidos.substring(0, delimitador);  // Extrae el primer dato
      dato2 = datos_leidos.substring(delimitador + 1);  // Extrae el segundo dato

      voltaje = dato1.toFloat();  // Convierte el primer dato a entero
      Nivelcm = dato2.toFloat();  // Convierte el segundo dato a entero
    }      
    Blynk.virtualWrite(V5, voltaje); 
    Blynk.virtualWrite(V6, Nivelcm);   
    //Serial.println(dato1);
    //Serial.println(dato2);
  }  
  /*
  datos_enviados++;
  //Blynk.virtualWrite(V3, datos_enviados); 
  if(datos_enviados > datos_a_enviar){ 
    Serial.println("Numero de datos enviados: " + String(datos_enviados));
    Serial.println("Entrando en suspensión.");
    Serial.flush();
   // esp_deep_sleep_start();
  }
  */
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  //Conectarse a la aplicación
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  //Definir el periodo de funcionamiento de la funcion del temporizador
  timer.setInterval(100L, myTimerEvent); 

  //++bootCount;
  //Serial.println("Inicio numero " + String(bootCount) + ".");

  //Activar el modo deep sleep
  //esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR); //Definir los segundos a dormir
  //Serial.println("Las tramas de datos se van a enviar cada " + String(TIME_TO_SLEEP) + " segundos."); //Mensaje para indicar cuanto va a domir la ESP32
}

void loop()
{
  Blynk.run();
  timer.run();
}

