#include "HMC5883L.h"
#include "Serial.h"

HMC5883L compass(p28,p27);

Serial PC(USBTX,USBRX);

//Magnetics values x,y,z
int readings[3];

//ID Buffer
char buffer[3];

 
int main() {

     PC.printf("Starting HMC5833L test...%c%c",13,10);
     
     //ID should be H43
     compass.getAddress(buffer);
     PC.printf("Magnetic Compass  Id=%c%c%c \n\r",buffer[0],buffer[1],buffer[2]);
     
    //Single mode, , 15Hz measurement rate.
     compass.stOpMode(0,112,160) 
   
     //Wait some time(Need at least 6ms)
     wait(.8);
     
        
     while(1){
    
    
        compass.readData(readings);
    
        pc.printf("Magnetic Values  Mx=%i, My=%i and Mz=%i %c%c",(int16_t)readings[0],(int16_t)readings[1],(int16_t)readings[2] ,13,10);
       
         wait(0.1);   
         
     
 
     }
 
}


