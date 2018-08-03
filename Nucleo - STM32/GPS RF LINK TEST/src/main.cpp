#include <mbed.h>

Serial pc(USBTX, USBRX); // tx, rx
Serial gps_link(PA_2, PA_3); //Arduino Header CN9

DigitalOut activityled(LED1);

int main() {
    gps_link.baud(9600);
    while(1) {
        // put your main code here, to run repeatedly:
        if(gps_link.readable()){
            pc.putc(gps_link.getc());
            activityled = !activityled;
        } else {
            pc.printf("\r\nGPS not availible");
        }
       
    }
}