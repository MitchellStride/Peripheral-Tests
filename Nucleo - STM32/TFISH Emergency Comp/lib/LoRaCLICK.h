#ifndef MBED_LoRaCLICK_H
#define MBED_LoRaCLICK_H

#include <mbed.h>
#include <string.h>

//Definition 

class Click {
    public:
        /** Creates LoRa Click Object 
         *  @param TX serial uart pin to which the click is connected
         *  @param RX serial uart pin to which the click is connected
         *  @param NWAKE mbed pin for MCU
         */
        Click(PinName TX, PinName RX, int baudrate = 115200, PinName NWAKE);

        /** Sets Mode
         *  Set Lora to Master Node or End Node
         *  @param mode var to set node - 0 master, 1 end 
         */
        void setMode(int mode);
        
        /** End Node function to look for a master
         *  
         *  Returns 1 when found pair?
         */
        int pairRequest();

        /** Master Node function to accept a request
         *  Add pair to id table
         */
        void pairAccept();

        /** Transmitting a Message
         * CS (Nwake) Pulled Low
         * Data Framing [0xAA][AT Command Code][Payload Data][Checksum]
         */
        void send(string message);

    private:
        //Set pins and variables
        Serial _uart;
        DigitalOut _wkpin;
        
        int _mode;
        

};


#endif