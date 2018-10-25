#include<Servo.h>
int servoPinL=0;//Left motor pin #
int servoPinR=1;//Right motor pin #
Servo servoL;
Servo servoR;

int sensor=2;//MAGENTIC Sensor pin #
int LED=3;//LED motor pin # (Part of Magnetic sensor)
int val;

int magCounter=0;
int maxCount=5;//max numbers of magnets it needs to sense

/*
 * This might actually move the robot backwards, so
 * please check if this code actually moves the robot forward.
 * If it doesn't change the moveForward to moveBackward and
 * also change the original moveBackward to MoveForward
 */
void moveStop(){
  servoL.write(90);
  servoR.write(90);
}

void moveForward(){
  servoL.write(0);
  servoR.write(180);
}

void moveBackward(){
  servoL.write(180);//check
  servoR.write(0);
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
 boolean detect=detectMag();
 if(detect){//true
  moveStop();
  milis(200);
  magCounter++;
  moveForward();
    if(magCounter>=maxCount){
      milis(400);
      exit(0);
    }
 }
 else{
  moveForward();
 }
}
