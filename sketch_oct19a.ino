//Bibliotheken inkludieren

#include <OneWire.h>
#include <DallasTemperature.h>

//pins benennen

#define ONE_WIRE_BUS 2
#define buttonPinCold 13
#define buttonPinHot 12
#define kalt 7
#define warm 8



//Nutzung des Temperatursensors

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//Globale Variablen

int Wasserstand;

//pins deklarieren

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(buttonPinCold, INPUT);
  pinMode(buttonPinHot, INPUT);
  pinMode(kalt, OUTPUT);
 pinMode(warm,OUTPUT);
  digitalWrite(kalt, HIGH);
  digitalWrite(warm,HIGH);
  Serial.begin(115200);
}

//Hauptprogramm
void loop()
{
  sensors.requestTemperatures();            //Temperatur anfragen
  double temp = sensors.getTempCByIndex(0); //Temperatur in Celsius in die Variable temp einschreiben
 
  delay(100);
  Serial.print("Wasserstand ");
  Wasserstand = analogRead(A0);             //Wasserstand auslesen
  Serial.println(Wasserstand);
  Serial.println(temp);
  int buttonStateCold = digitalRead(buttonPinCold);
 
  //Drucktaster für Kalte Einstellung
  if(buttonStateCold == HIGH)
  {  
    Serial.println("1");
    digitalWrite(kalt, LOW);
  }
 
  //Motor soll stoppen bei einem Wasserstand von über 470
  if(Wasserstand <= 300)
  {
    
    Serial.println("x");

 
  //Temporärer Code zum Testen von Erkennung der Temperatur
  if(temp > 27.00 )        
  {
    delay(200);
    Serial.println("Zu Heiß");
    digitalWrite(kalt, LOW);
    digitalWrite(warm, HIGH);
    
        
  }      
  if(temp < 24.00)
  {
   
    delay(200);
    Serial.println("Zu Kalt");
    digitalWrite(warm, LOW);
    digitalWrite(kalt, HIGH);
    
  }

  if(temp >= 24 && temp <= 27){
    delay(200);
    Serial.println("perfekt");
    digitalWrite(warm, LOW);
    digitalWrite(kalt, LOW);
    
    }
  }
  if(Wasserstand >=300)
  {
    delay(200);
    Serial.println("full");
    digitalWrite(warm, HIGH);
    digitalWrite(kalt, HIGH);
    }
}