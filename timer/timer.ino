
#include <ZumoMotors.h>
#include <ZumoBuzzer.h>

unsigned long time;
ZumoMotors motors;
ZumoBuzzer buzzer;
void setup(){
  Serial.begin(9600);
  
}
void loop(){
 
time = millis();
 Serial.println(time);


  if (time < 4000){
     motors.setLeftSpeed(50);
     motors.setRightSpeed(50);
    
  } else if(time > 4000 ){
    

buzzer.playNote(NOTE_G(3),200,15);
       motors.setLeftSpeed(0);
       motors.setRightSpeed(0);
        
 }

}




 


///////////////////////
//   
//  if ( time < 13000){
//    Serial.print(" under 1000 OFF; ");
//    Serial.println(time);
//    motors.setLeftSpeed(50);
//    motors.setRightSpeed(50);
//    
//  } else  {
//    Serial.print(" under 2000 ON; ");
//   Serial.println(time);
//    motors.setLeftSpeed(0);
//    motors.setRightSpeed(0);
//    
//  }



