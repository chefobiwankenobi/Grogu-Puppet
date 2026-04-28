#include <Servo.h>
int headPin = 2;
int leftUpPin = 7;
int leftDownPin = 8;
int rightUpPin = 10;
int rightDownPin = 11;
int headReading;
int leftArmAngle = 0;
int rightArmAngle = 0;

boolean leftUpState = false;
boolean leftDownState = false;

boolean rightUpState = false;
boolean rightDownState = false;


//declare my vars
Servo head;
Servo leftArm;
Servo rightArm;





void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode (headPin, INPUT);
 pinMode (rightUpPin, INPUT);
 pinMode (rightDownPin, INPUT);


//attach servo var to a pin
head.attach(5);
leftArm.attach(6);
rightArm.attach(4);

}

void loop() {
headReading = analogRead(headPin);
leftUpState = digitalRead(leftUpPin);
leftDownState = digitalRead (leftDownPin);
rightUpState = digitalRead(rightUpPin);
rightDownState = digitalRead (rightDownPin); 






//head controls
int mappedHeadReading = map(headReading, 0, 1023, 0, 210);
  head.write(mappedHeadReading);
Serial.println(rightUpState);
Serial.println(rightDownState);
leftArm.write(leftArmAngle);
rightArm.write(rightArmAngle);

//right arm controls 
if (rightUpState == true){
  
  Serial.println ("up working");
  if (rightArmAngle <= 181){
    rightArmAngle+=5;
  }
} 
if (rightDownState == true){
  
Serial.println("down working");
if (rightArmAngle >= 0){
 rightArmAngle-=5;
  }
} 


//left arm controls 
if (leftUpState == true){
  
  Serial.println ("up working");
  if (leftArmAngle <= 181){
  leftArmAngle+=5;
  }
} 
if (leftDownState == true){
  
Serial.println("down working");
if (leftArmAngle >= 0){
   leftArmAngle-=5;
  }
}

}
