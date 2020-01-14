#include <mbed.h>

DigitalOut myled(PA_5);
Serial pc(USBTX, USBRX); // tx, rx

int main() {

    // put your setup code here, to run once:


    while(1) {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
        pc.printf("Hello World!\n");
        pc.printf("I am a serial link!!\n");
    }
}