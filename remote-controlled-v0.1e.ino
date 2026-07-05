#include <irRemote.hpp>
#include <Servo.h>
//IRremote library v4.4.0 is required


const int steeringPin = 9;
const int motorControl = 8;
const int irPin = 3;
const int headPin = 5;
const int blueLed = 13;
const int redLed = 12;
const int usTrig = 10;
const int usEcho = 11;
const int buzzer = 7;

uint64_t decCode;

void setup() {
    IrReceiver.begin(irPin);
    pinMode(motorControl, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT)
    steeringServo.attach(steeringPin);
    headServo.attach(headPin);
    steeringServo.write(90);
    headServo.write(90);

}

void loop() {
   if(IrReceiver.decode())  // If we receive a signal from the IR receiver
  {
    decCode = IrReceiver.decodedIRData.decodedRawData;  
    

    if(decCode == 7477 || decCode == 5429)  
    {
       digitalWrite(blueLed, HIGH);
    }
    else if(decCode == 7478 || decCode == 5430) {
        digitalWrite(blueLed, LOW);
    }
    IrReceiver.resume();  // Receive the next value
  }  
  
}