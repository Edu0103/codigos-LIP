#include <TimerOne.h>                    
#include <MultiFuncShield.h>             

int distance = 0;
bool ligado = false;                      

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Timer1.initialize();                    
  MFS.initialize(&Timer1);                
  MFS.write("OFF");                      
}

void loop() {
  byte btn = MFS.getButton();             

  if (btn == BUTTON_1_PRESSED) {
    ligado = !ligado;                     

    if (ligado) {
      MFS.write("ON");                    
    } else {
      MFS.write("OFF");                  
    }
    delay(150); 
  }

  if (ligado) {
    distance = 0.01723 * readUltrasonicDistance(5, 6);
    MFS.write(distance);
    delay(200);
    if(distance > 50){
    MFS.writeLeds(LED_1,OFF);
    MFS.writeLeds(LED_2,OFF);
    MFS.writeLeds(LED_3,OFF);
    }else{
      if (distance <= 50 && distance >= 30){
    MFS.writeLeds(LED_1,ON);
    MFS.writeLeds(LED_2,OFF);
    MFS.writeLeds(LED_3,OFF);}

    if (distance <= 30 && distance >= 15) {
    MFS.writeLeds(LED_1,ON);
    MFS.writeLeds(LED_2,ON);
    MFS.writeLeds(LED_3,OFF);}

    if (distance < 15) {
    MFS.writeLeds(LED_1,ON);
    MFS.writeLeds(LED_2,ON);
    MFS.writeLeds(LED_3,ON);
    MFS.beep(5, 
           5, 
           1, 
           3, 
           distance
          );
    }
    }
    
    }
}