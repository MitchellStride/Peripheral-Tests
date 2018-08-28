#include <mbed.h>

DigitalOut userLED1(PC_9);

Serial xport(PA_2, PA_3); //Lantronix UART

int main() {
    // put your setup code here, to run once:
   xport.baud(9600);
    xport.printf("\n\r\n\r\n\r\n\rSetup...\n");

    while(1) {
        // put your main code here, to run repeatedly:
         xport.printf("\n\rHello Kraken!");
         wait_ms(100);
        }
}