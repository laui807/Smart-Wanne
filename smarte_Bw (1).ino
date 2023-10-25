
//Bibliotheken inkludieren

#include <OneWire.h>
#include <DallasTemperature.h>

//pins benennen

#define ONE_WIRE_BUS 2
#define buttonPinCold 13
#define buttonPinHot 12
#define Steuerpin 7


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
  pinMode(Steuerpin, OUTPUT);
  
  digitalWrite(Steuerpin, HIGH); 
  Serial.begin(9600); 
}

//Hauptprogramm
void loop() 
{
  sensors.requestTemperatures();            //Temperatur anfragen
  double temp = sensors.getTempCByIndex(0); //Temperatur in Celsius in die Variable temp einschreiben
  
  delay(1000);
  Serial.print("Wasserstand ");
  Wasserstand = analogRead(A0);             //Wasserstand auslesen
  Serial.println(Wasserstand);
  Serial.println(temp);
  int buttonStateCold = digitalRead(buttonPinCold);
  
  //Drucktaster für Kalte Einstellung
  if(buttonStateCold == HIGH) 
  {  
    Serial.println("1");
    digitalWrite(Steuerpin, LOW); 
  }
  
  //Motor soll stoppen bei einem Wasserstand von über 470
  if(Wasserstand >= 470)
  {
    digitalWrite(Steuerpin, HIGH);
  }

  //Temporärer Code zum Testen von Erkennung der Temperatur
  if(temp > 27.00)        
  { 
    delay(2000);
    Serial.println("Zu Heiß");     
  }      
  if(temp < 24.00)
  { 
    delay(2000);
    Serial.println("Zu Kalt");
  } 
}
