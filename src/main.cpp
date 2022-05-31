#include <Arduino.h>
const int LedVerd = 19;
const int LedGroc = 18;
const int LedVermell = 17;

bool LVerd = true;
bool LG = false;
bool LRed = false;

void TascaVerd (void * parameter){
for(;;){ // infinite loop
while(LG== true or LRed == true or LVerd == false) //si està encès algun led no fer res
{vTaskDelay(50 / portTICK_PERIOD_MS);}

// Encenc led verd durant 5000ms
Serial.println ("Led Verd ON");
digitalWrite(LedVerd, HIGH);
vTaskDelay(5000 / portTICK_PERIOD_MS);
// Apaguem led verd
Serial.println ("Led Verd OFF");
digitalWrite(LedVerd, LOW);
LVerd= false;
LG=true; // dona pas a que es realitzi la tasca del Led Groc
}
}

void TascaGroc (void * parameter){
for(;;){
  while (LVerd== true or LRed==true or LG==false)
  {vTaskDelay(50 / portTICK_PERIOD_MS);}
LG=true;
 // Obre el led 4 vegades
for(int i=0;i<4;i++)
{
Serial.print ("Led Groc ON per ");
Serial.print (i+1);
Serial.println ("a vegada");
// 900ms encès
digitalWrite(LedGroc, HIGH);
vTaskDelay(900 / portTICK_PERIOD_MS);
// 900ms apagat
Serial.println ("Led Groc OFF");
digitalWrite(LedGroc, LOW);
vTaskDelay(900 / portTICK_PERIOD_MS);
}
LG=false;
LRed = true; // dono pas a que es realitzi la tasca del Led Vermell

}
}


void TascaVermell (void * parameter){
for(;;){ // infinite loop
while(LG== true or LVerd == true or LRed==false) //si està encès algun led no fer res
{vTaskDelay(50 / portTICK_PERIOD_MS);}

// // Encenem led vermell durant 5000ms
Serial.println ("Led Vermell ON");
digitalWrite(LedVermell, HIGH);
vTaskDelay(5000 / portTICK_PERIOD_MS);
//apaguem led vermell 
Serial.println ("Led Vermell OFF");
digitalWrite(LedVermell, LOW);
LRed= false;
LVerd=true; // donem pas a que es realitzi la tasca del led verd
}
}


void setup() {

  Serial.begin(115200);
  
pinMode(LedVerd, OUTPUT);
pinMode (LedGroc,OUTPUT);
pinMode (LedVermell,OUTPUT);

xTaskCreate(
TascaVerd, // Function that should be called
"Tasca verd", // Name of the task (for debugging)
1000, // Stack size (bytes)
NULL, // Parameter to pass
1, // Task priority La prioritat pot anar entre 0 i 24 com + alta + prioritat
NULL // toggleLEDHandle // Task handle
);

  xTaskCreate(
TascaGroc, // Function that should be called
"Tasca Groc", // Name of the task (for debugging)
1000, // Stack size (bytes)
NULL, // Parameter to pass
1, // Task priority La prioritat pot anar entre 0 i 24 com + alta + prioritat
NULL // toggleLEDHandle // Task handle
);

xTaskCreate(
TascaVermell, // Function that should be called
"Tasca vermell", // Name of the task (for debugging)
1000, // Stack size (bytes)
NULL, // Parameter to pass
1, // Task priority La prioritat pot anar entre 0 i 24 com + alta + prioritat
NULL // toggleLEDHandle // Task handle
);

}

void loop() {
  // put your main code here, to run repeatedly:
}