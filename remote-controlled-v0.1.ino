#include <irRemote.h>

int recv_pin = 3;
IRrecv irrecv(recv_pin);
decode_results results;

void setup() {
    irrecv.enableIRIn();

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