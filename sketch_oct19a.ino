#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#define buttonPinCold 12
#define buttonPinHot 13
#define Steuerpin 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


int Wasserstand;
int Temperatur;




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
  double temp = sensors.getTempCByIndex(0);
 delay(1000);
  Wasserstand = analogRead(A0);
  Serial.print(Wasserstand);
  Serial.println("Wasserstand");
  sensors.requestTemperatures(); 
  Serial.println(temp);
  int buttonStateCold = digitalRead(buttonPinCold);



  if(buttonStateCold == HIGH) {  //Ob der knopf fürs kalte bad gedrückt wurde 
      digitalWrite(Steuerpin, LOW); // Steuere den relaise an
       
}


   if(Wasserstand >= 470){
      digitalWrite(Steuerpin, HIGH);
    }



end:
   if(temp > 27.00){ 
    delay(2000);
             Serial.println("Zu Heiß");     
               goto end;
            
   }      


   end2:
   if(temp < 24.00){ 
    delay(2000);
             Serial.println("Zu Kalt");     
               goto end2;
            
   }  






  


    
   // int buttonStateHot = digitalRead(buttonPinHot);
  //if(buttonStateHot == HIGH) { 
    //digitalWrite(Steuerpin, LOW);
    //}

  
 
}