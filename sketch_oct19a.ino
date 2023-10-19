#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#define buttonPinCold 12
#define buttonPinHot 13
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


int Wasserstand;
int Temperatur;
int temp = 0;



void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(buttonPinCold, INPUT);
  pinMode(buttonPinHot, INPUT);
  pinMode(Steuerpin, OUTPUT);
  digitalWrite(Steuerpin, HIGH);
  Serial.begin(9600); 
  }

void loop() {
 delay(1000);
  Wasserstand = analogRead(A0);
  Serial.print(Wasserstand);
  Serial.println("Wasserstand");
  sensors.requestTemperatures(); 
  Serial.println(sensors.getTempCByIndex(0));
  int buttonStateCold = digitalRead(buttonPinCold);
  if(buttonStateCold == High) { 
   digitalWrite(Steuerpin, LOW);
    }


    
    int buttonStateHot = digitalRead(buttonPinHot);
  if(buttonStateHot == High) { 
    digitalWrite(Steuerpin, LOW);
    }

  
 
}