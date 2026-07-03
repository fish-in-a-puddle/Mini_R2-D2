#include <irRemote.h>

const int steeringPin = 9;
const int motorControl = 8;
const int irPin = 3;
const int headPin = 5;
const int blueLed = 13;
const int redLed = 12;
const int usTrig = 10;
const int usEcho = 11;
const int buzzer = 7;

IRrecv irrecv(irPin);
decode_results results;

void setup() {
    irrecv.enableIRIn();
    pinMode(motorControl, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT)
    steeringServo.attach(steeringPin);
    headServo.attach(headPin);
    steeringServo.write(90);
    headServo.write(90);

}

void loop() {
    int ir_value
    if (irrecv.decode(&results)) {
        ir_value = (results.value, HEX);
        irrecv.resume();
        case (ir_value == ) {

        }
    }
}