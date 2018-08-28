
#include <mbed.h>

DigitalOut activityled(PC_9);
DigitalOut userLED(PA_8);

 //Init Serial for debug
Serial xport(PA_2, PA_3); //Lantronix UART
Serial gps_link(PA_9, PA_10);

int main() {
    gps_link.baud(9600);
    while(1) {
        // put your main code here, to run repeatedly:
        if(gps_link.readable()){
            xport.putc(gps_link.getc());
            activityled = !activityled;
        } else {
            xport.printf("\r\nGPS not availible");
        }
       
    }
}