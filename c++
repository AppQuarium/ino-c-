#include "DHT.h"
#include "Time.h"
#define Blue  9                    
#define Sunlight  11                                             
DHT dht(2, 11); 
char aux;
int t,h,i;


void setup() { 
 pinMode(Blue, OUTPUT);       
 pinMode(Sunlight, OUTPUT);
 digitalWrite(Blue,LOW);
 digitalWrite(Sunlight,LOW);
 Serial.begin(9600);
}

void loop() {
   t = dht.readTemperature();
   t = t - 4 ;
   h = dht.readHumidity();
 

  
    if (Serial.available())
  {
    aux=Serial.read();
                 
          if(aux == 'r')
          {
            testlight();
        
                  }
          if(aux == 's')
          {
          Serial.print(t);
          Serial.print(" ");
          Serial.print(h);
          Serial.print(" ");
          Serial.println("");
          }
             
}
}


  void testlight(){
    for(i=0;i<33;i++){
   digitalWrite(Blue,HIGH);
   delay(i);
   digitalWrite(Blue,LOW);
   digitalWrite(Sunlight,HIGH);
   delay(i*2);
   digitalWrite(Sunlight,LOW);
   
}
  }
         
