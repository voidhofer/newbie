#include "MicroBit.h"
#include "Tests.h"

void
timer_loop() {
    int loopcount = 0;
    while (1) {
        loopcount++;
        uBit.sleep(1000);
        uBit.serial.send(loopcount);
        MicroBitEvent evt(55005, 3);
        if (loopcount % 60 == 0) {
            MicroBitEvent evt(55005, 2);
        }
        if (loopcount % 3600 == 0) {
            MicroBitEvent evt(55005, 1);
        }
    }
}