# PRÀCTICA 4 - Exerici 2 -  Semàfor

El que em demana aquest exercici ja ho he realitzat en l'exercici previ, del qual he adjuntat vídeo. Tot i així tornaré a crear un programa amb diverses tasques relacionades, concretament simularé un semàfor. El muntatge a la protobord consisteix en un led vermell, un de groc i un de verd connectats cadascun en sèrie amb una resistència de 330Ohm. 

Busco crear un bucle infinit on primer estigui encès el led verd una estona, després faci unes 4 pampallugues el led groc i després s'encengui el led vermell. Volem que s'executi una acció rere l'altra, i que un led no s'encengui fins que l'anterior no s'ha apagat. És per això que crearem tres variables bool, una per cada led. Aquestes no indicaran si el led està apagat o no sinó que indicaran que una tasca ja s'ha acabat i donaran peu a que comenci la següent. He descrit les tasques d'aquesta manera: 

```C
bool LVerd = true;
bool LG = false;
bool LRed = false;

void TascaVerd (void * parameter){
for(;;){ 
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
```





El següent vídeo mostra el correcte funcionament d'aquest programa:  


[Vídeo funcionament Ex2 semàfor](https://drive.google.com/file/d/1NUV73hOC1Meyho9UltKCY31FsR6IxAu-/view?usp=sharing "link al drive")

--- 

