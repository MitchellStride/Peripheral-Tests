/********************************************
 *  THUNDER FISH EMERGENCY COMPUTER TESTING
 * 
 *  GNSS 5 Click - https://www.mikroe.com/gnss-5-click
 *      Serial Monitoring using a function
 *  LoRa 3 Click -  https://www.mikroe.com/lora-3-click
 *      LoRa packet radio header
 * 
 * ******************************************/

#include <mbed.h>
#include <LoRaCLICK.h>
#include <string.h>

DigitalOut activityLED(PC_9);
DigitalOut userLED2(PA_8);

Serial xport(PA_2, PA_3); //Lantronix UART
Serial gps(); // For Serial getc test

Click LoRa1(TX, RX, NWAKE);

void gpsMonitor(){
    while(1){
        if(gps.readable()){
            xport.putc(gps.getc());
            activityLED = !activityLED;
        } else {
        }
    }
}

int main() {
    xport.baud(9600);
    gps.baud(9600);
    xport.printf("\n\r\n\r\n\rSetup..........");
    //gpsMonitor();

    while(1) {
        //Monitor pressure sensors, leak, temperature


        /***************************************
         * Emergency condtions met. 
         *      Drop Nose & Tail Weights, Start Flasher
         *      GPS/Iridum Broadcast through LoRa
         *      Thunderfish screams "Help me im drowning on all comms ports"
         * *************************************/


    }
 }
