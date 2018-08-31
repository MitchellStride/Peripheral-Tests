//Overall Operation

/*************************************
 * MODES
 * 
 * Master Node
 * Pairing command to accepet pair request from end node
 * 
 * End Node
 * Pairing request command
 * **********************************/

/*************************************
 * COMMUNICATION
 * 
 * Transmitting a Message
 * CS (Nwake) Pulled Low
 * Data Framing [0xAA][AT Command Code][Payload Data][Checksum]
 * 
 * Recieving a Message
 * NDATA gets pulled low by module
 * Module sends UART TX blast
 * Waits for NWAKE to transmit again
 * **********************************/


//Implementation 

#include <mbed.h>
#include <LoRaCLICK.h>
#include <string.h>

//Declarations
Click::Click(PinName TX, PinName RX, int baudrate, PinName NWAKE) :
            _uart(TX, RX),
            _wkpin(NWAKE) {
            _uart.baud(baudrate);
        }

//Functions
        void Click::setMode(int mode) : _mode(mode){
            switch(_mode){
                case 0:
                    //master node
                    //set device as master and enable pairing, wait for pair request --- write 0 to eeprom?
                    break;
                case 1:
                    //end node
                    //set device as slave and send pair requests --- write 2-5 to eeprom?
                    break:
                default:
                    //You dun goofed, ain't no error handling in these parts.
                    // Rest in peace thunderfish, no LoRa.
                    break;
            }
        }
        
        int Click::pairRequest(){
            // use send function with command
        }


        void Click::pairAccept(){
            //if this command pair
        }

        void Click::send(string message){
            //uart send
            //Data Framing [0xAA][AT Command Code][Payload Data][Checksum]
        }

}


/* Test Code

//setup serial connection to xport for debugging and reading messages
Serial xport(PC_4, PC_5);

//setup 2 serials connections between Clicks and Artemis
Click LoRaMaster(PD_2, PC_12, PA_8;
Click LoRaSlave(PA_9, PA_10, PC_9);

string msg = "Hello there RF/LoRa wizard..."

    int main(){
        xport.baud(9600);

        LoRaMaster.setMode(0);
        LoRaSlave.setMode(1);

        LoRaSlave.pairRequest();
        LoRaMaster.pairAccept();


            while(1){
                LoRaMaster.send(msg);
                
                //buffered or repeat like 30 times????
                //xport.putc(LoRaMaster.getc());
            }

        

}
*/