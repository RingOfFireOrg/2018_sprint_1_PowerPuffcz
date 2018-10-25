#include<Servo.h>
int servoPinL=0;
int servoPinR=1;
Servo servoL;
Servo servoR;

int sensor=2;
int LED=3;
int val;

int magCounter=0;
int maxCount=5;

void moveForward(){
  for(int angle=0; angle<361; angle++){
    servoL.write(angle);
    servoR.write(360-angle);//check
 }
}

void moveBackward(){
  for(int angle=360; angle>-1; angle--){
    servoL.write(360-angle);//check
    servoR.write(angle);
 }
}

void detectMag(){
  boolean detect;
  val= digitalRead(sensor);
  if(val==LOW){
    digitalWrite(LED,HIGH);
    detect=true;
  }
  else{
    digitalWrite(LED,LOW);
    detect=false;
  }
}

void setup() {
  servoL.attach(servoPinL);
  servoR.attach(servoPinR);
  pinMode(led, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
 boolean detect= detectMag();
 if(magCounter==maxCount){
  if(){//add case to stop moving back
    
  }
  else{
    moveBackward();
  }
 }
 else if(detect){//true
  delay();
  magCounter++;
  moveForward();
 }
 else{
  moveForward();
 }
}
