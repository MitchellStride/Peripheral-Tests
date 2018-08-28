/********************************************
 *  THUNDER FISH EMERGENCY COMPUTER TESTING
 * PNs
 *  LINX GPS Test Module - EVM-GPS-R4-ND
 *  GNSS 5 Click - https://www.mikroe.com/gnss-5-click
 * ******************************************/

#include <mbed.h>
#include "GPS.h"

DigitalOut activityLED(PC_9);
DigitalOut userLED2(PA_8);

Serial xport(PA_2, PA_3); //Lantronix UART
Serial gps(PA_9, PA_10); // For Serial getc test
//GPS gps(PA_9, PA_10);

int main() {
    xport.baud(9600);
    xport.printf("\n\r\n\r\n\rSetup..........");
    gps.baud(9600);

    while(1) {
    if(gps.readable()){
            xport.putc(gps.getc());
            activityLED = !activityLED;
        } else {
        }
    }
 }
