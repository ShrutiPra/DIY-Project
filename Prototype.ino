#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>



Servo servo;



char auth[] = "plF-UcJQqrMCXoYlsCLzKleIhZCi3nvZ";

char ssid[] = "Linksys597";

char pass[] = "2ea996a7";
int pos=0;


void setup()

{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);



  servo.attach(15); // NodeMCU D8 pin

  

 }

  

void loop()

{

  

  Blynk.run();

  

}


BLYNK_WRITE(V2)

{
for (pos=0; pos<=180; pos += 5){
  servo.write(pos);

}
  
for (pos = 180; pos>=0; pos -= 5){
  servo.write(pos);
delay(10);
}
  
  

}

BLYNK_WRITE(V3)

{
for (pos=0; pos<=180; pos += 5){

  servo.write(pos);

}

for (pos=180; pos >= 0; pos -= 5){

  servo.write(pos);
    delay(10);
 
}
}
