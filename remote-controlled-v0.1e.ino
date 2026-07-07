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
const int buzzer = 4;

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
    headServo.write(90);

}

void loop() {
   if(IrReceiver.decode())

    decCode = IrReceiver.decodedIRData.decodedRawData;  

    if(decCode == 7477 || decCode == 5429)  
    {
      steeringServo.write(90);
       digitalWrite(motorPlus, HIGH);
       digitalWrite(motorMinus, LOW);
    }
    else if(decCode == 7478 || decCode == 5430) {
        digitalWrite(motorPlus, LOW);
        digitalWrite(motorPlus, LOW);
    }
    else if(decCode == 7457 || decCode == 5409) {
      steeringServo.write(45);
    }
    else if (decCode == 7456 || decCode == 5408) {
      steeringServo.write(135);
    }
    delay(50);
    IrReceiver.resume;
  }  
  
}