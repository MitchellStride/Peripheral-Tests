#include <mbed.h>

//Init Serial for debug
Serial pc(USBTX, USBRX);

//Pin Assignments
DigitalOut userLED1(PC_9);
DigitalOut userLED2(PA_8);


int main() {
    //Setup Code
    pc.printf("Setup...\n");

    while(1) {
        //Loop Code

        //User LEDs
        userLED1 = !userLED1; 
        userLED2 = !userLED1;
        wait(1.0);

    }
}


