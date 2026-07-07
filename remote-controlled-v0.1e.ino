#include <IRremote.hpp>
#include <Servo.h>
//IRremote library v4.4.0 is required

// Establish pins
const int steeringPin = 9;
const int motorPlus = 8;
const int motorMinus = 7;
const int irPin = 3;
const int headPin = 5;
const int blueLed = 13;
const int redLed = 12;
const int usTrig = 10;
const int usEcho = 11;
const int speakerPin = 6;
const int ledPin = 13;
int motorMode = 0;
int steeringPosition = 90;

uint64_t decCode;
Servo headServo, steeringServo;

void setup() {
    IrReceiver.begin(irPin);
    pinMode(motorPlus, OUTPUT);
    pinMode(motorMinus, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    digitalWrite(motorPlus, LOW);
    digitalWrite(motorPlus, LOW);
    steeringServo.attach(steeringPin);
    headServo.attach(headPin);
    steeringServo.write(90);
    steeringPosition = 90;
    headServo.write(90);


}

// Functions for sound generator:

void phrase1() {
    
    int k = random(1000,2000);
    digitalWrite(ledPin, HIGH);
    for (int i = 0; i <=  random(100,2000); i++){
        
        tone(speakerPin, k+(-i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(ledPin, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (i * 10));          
        delay(random(.9,2));             
    } 
}

void phrase2() {
    
    int k = random(1000,2000);
    digitalWrite(ledPin, HIGH);  
    for (int i = 0; i <= random(100,2000); i++){
        
        tone(speakerPin, k+(i*2));          
        delay(random(.9,2));             
    } 
    digitalWrite(ledPin, LOW);   
    for (int i = 0; i <= random(100,1000); i++){
        
        tone(speakerPin, k + (-i * 10));          
        delay(random(.9,2));             
    } 
}


void loop() {
   if(IrReceiver.decode())

    decCode = IrReceiver.decodedIRData.decodedRawData;  

    if(decCode == 7477 || decCode == 5429)  
    {
      if (motorMode == 0) {
      digitalWrite(motorPlus, HIGH);
      digitalWrite(motorMinus, LOW);
      motorMode = 1;
      }
    }
    else if(decCode == 7478 || decCode == 5430) {
      if (motorMode == 1) {
      digitalWrite(motorPlus, LOW);
      digitalWrite(motorMinus, LOW);
      motorMode = 0;
      }
    }
    else if(decCode == 7457 || decCode == 5409) {
      steeringPosition = steeringServo.read;
      if (steeringPosition << 90) {
        steeringServo.write(90);
        steeringPosition = 90;
      }
      else if (steeringPosition << 135) {
        steeringServo.write(135);
        steeringPosition = 135;
      }
    }
    else if (decCode == 7456 || decCode == 5408) {
      steeringPosition = steeringServo.read;
      if (steeringPosition >> 90) {
        steeringServo.write(90);
        steeringPosition = 90;
      }
      else if (steeringPosition >>45) {
        steeringServo.write(45);
        steeringPosition = 45;
      }
    }
    else if (decCode ==7474 || deCode == 5426) {
      // Sound generator code:
      int K = 2000;
    switch (random(1,7)) {
        
        case 1:phrase1(); break;
        case 2:phrase2(); break;
        case 3:phrase1(); phrase2(); break;
        case 4:phrase1(); phrase2(); phrase1();break;
        case 5:phrase1(); phrase2(); phrase1(); phrase2(); phrase1();break;
        case 6:phrase2(); phrase1(); phrase2(); break;
    }
    for (int i = 0; i <= random(3, 9); i++){
        
        digitalWrite(ledPin, HIGH);  
        tone(speakerPin, K + random(-1700, 2000));          
        delay(random(70, 170));  
        digitalWrite(ledPin, LOW);           
        noTone(speakerPin);         
        delay(random(0, 30));             
    } 
    noTone(speakerPin);         
    delay(100);
    }
    delay(50);
    IrReceiver.resume;
  }  
  
}