#include <irRemote.h>

int recv_pin = 3;
IRrecv irrecv(recv_pin);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();

}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume();
    }
}