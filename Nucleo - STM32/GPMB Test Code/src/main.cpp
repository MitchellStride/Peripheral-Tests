#include <mbed.h>
#include <BME280.h>
#include <DS1820.h>


//Pin Assignments
DigitalOut userLED1(PC_9);
DigitalOut userLED2(PA_8);
DigitalOut LOAD0(PA_1);
DigitalOut LOAD1(PA_6);
DigitalOut SPI3_MOSI(PC_12);  //SPI BUS & ISO GPIO
DigitalOut SPI3_SCK(PC_10);    //SPI BUS & ISO GPIO
DigitalOut BI_ISO_GPIO1(PB_14);
DigitalOut BI_ISO_GPIO2(PB_15);
//DigitalIn BI_ISO_GPIO1(PB_14);
//DigitalIn BI_ISO_GPIO2(PB_15);
DigitalIn SPI3_MISO(PC_11);  //SPI BUS & ISO GPIO
DigitalIn SPI3_SS(PB_13);
DigitalIn leak1(PB_11);
DigitalIn leak2(PB_10);
DigitalIn sync(PC_13);

AnalogOut DAC1_OUT(PA_4);
AnalogIn P9_Ain1(PC_0);
AnalogIn P9_Ain1(PC_0);
AnalogIn P9_Ain1(PC_0);
//AnalogIn LM35(PA_7);

I2C i2c(PB_7, PB_6);

 //Init Serial for debug
Serial xport(PA_2, PA_3); //Lantronix UART

//Devices
BME280 BME(PB_7, PB_6);
DS1820  ds1820(PC_3);

//Variables
float pressure;
float tempBME;
float humidity;

//float tempLM35;

int l1;
int l2;

int main() {
    //Setup Code
    xport.baud(9600);
    xport.printf("\n\r\n\r\n\r\n\rSetup...\n");
    
    i2c.frequency(100000);

    //I2C I/O EXPANDER
            //SWITCH CODE

    while(1) {
        //Loop Code

        //User LEDs
        /*userLED1 = !userLED1;
        userLED2 = userLED1; */
        
        //BME280
        xport.printf("\n\r\n\r\n\rEnviromental Monitoring:\n\r");
        pressure = BME.getPressure();
        tempBME = BME.getTemperature();
        humidity =  BME.getHumidity();
        xport.printf("temp:%.2fC\n\r", tempBME);
        xport.printf("pres:%.2fkPa\n\r", pressure/1000);
        xport.printf("humi:%.2f\n\r", humidity);

        //TEMP SENSING
            /*tempLM35 = (float(LM35.read())*5/(1023))/0.01;
            xport.printf("\n\rLM35 = %3.1fC\r\n", tempLM35);*/
            //DS18B20     - Set 4.7k Pullup
            if(ds1820.begin()) {
            ds1820.startConversion();   // start temperature conversion
            //wait(1.0);                  // let DS1820 complete the temperature conversion
            xport.printf("DS18B20 = %3.1fC\r\n", ds1820.read());     // read temperature
            } else {
                 xport.printf("\n\rNo DS1820 sensor found!\r\n");
            }

        //LEAK SENSING
        l1 = !leak1;
        l2 = !leak2;
        xport.printf("leak1:%i\n\r", l1);
        xport.printf("leak2:%i\n\r", l2);
            //LEAK LEDS
        if(l1)
            userLED1 = 1;
        else
            userLED1 = 0;
        if (l2)
            userLED2 = 1;
        else
            userLED2 = 0;

        //Load Switches
        LOAD0 = 1; //Turn on Load Switches
        LOAD1 = 1;

        //SYNC Testing
        if(!sync){
            userLED1 = 1;
            xport.printf("\n\rSYNC pulled LOW\r\n");
         } else
            userLED1 = 0;

        //Analog IN Header
        float AnValue = P9_Ain1.read();
        DAC1_OUT.write(1);
        xport.printf("DAC-OUT:%.2fV\n\r", AnValue);

        //GPIO Isolater TEST
        SPI3_SCK = 1;
        SPI3_MOSI = 1;

        
        if(SPI3_MISO)
            userLED1 = 1;
          else
            userLED1 = 0;
        if(SPI3_SS)
            userLED2 = 1;
          else
            userLED2 = 0;
        
        BI_ISO_GPIO1 = 1;
        BI_ISO_GPIO2 = 1;

        //CAN

        //RS232/485

        //IO


        wait_ms(1000);
    }
}


