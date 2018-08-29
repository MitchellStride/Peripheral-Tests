#include <mbed.h>

DigitalOut relay(PB_5);
DigitalOut light(PB_3);

//Serial pc(USBTX, USBRX);

void pwrCYCLE(int cycles, int timeOFF, int timeON){
    for(int count = 0; count < cycles; count++){
        //Load ON
        relay = 1;
        light = 1;
        wait_ms(timeON);
        //LOAD OFF
        relay = 0;
        light = 0;
        wait_ms(timeOFF);
        //Display & Repeat
        //pc.printf("Cycle %i", count, " of %i", cycles, " complete\n\r");
    }
}

int main(){
    //pc.baud(9600);
    //pc.printf("Power Cycling Begin\n\r");
    wait_ms(1000);
    //Set cycles, and time intervals in ms.
        pwrCYCLE(5000, 250, 1000);
    while(1){
        //pc.printf("\n\n\rPower Cycling Complete!\n\r");
        relay = 0;
        light = 1;
        while(1){};
    }
}