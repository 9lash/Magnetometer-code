#include "HMC5883L.h"
#include "Serial.h"
HMC5883L::HMC5883L(PinName sda,PinName scl) 
{

    i2c_ = new I2C(sda, scl);
    //100KHz, as specified by the datasheet.
    i2c_->frequency(100000);
}

void HMC5883L::setSleepMode() {
    
    write(HMC5883L_MODE, HMC5883L_SLEEP);
}

void HMC5883L::setDefault(void) {
   
   write(HMC5883L_CONFIG_A,HMC5833L_15_HZ_NORMAL);
   write(HMC5883L_CONFIG_B,HMC5833L_1_33GA);
   write(HMC5883L_MODE,HMC5883L_SINGLE);
   wait_ms(100);
}

void HMC5883L::getAddress(char *buffer) {
    
   char rx[3];
   char tx[1];
   tx[0]=HMC5883L_IDENT_A;
    
       
    i2c_->write(HMC5883L_I2C_WRITE, tx,1);
   
    wait_ms(1);
    
    i2c_->read(HMC5883L_I2C_READ,rx,3);
    
    buffer[0]=rx[0];
    buffer[1]=rx[1];
    buffer[2]=rx[2];
}



void HMC5883L::setOpMode(int mode, int ConfigA, int ConfigB) {
    
    
    write(HMC5883L_CONFIG_A,ConfigA);
    write(HMC5883L_CONFIG_B,ConfigB);
    write(HMC5883L_MODE,mode);
    

}


void HMC5883L::readData(int* readings)
 {

  
    char tx[1];
    char rx[2];
    
    
    tx[0]=HMC5883L_X_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    readings[0]= (int)rx[0]<<8|(int)rx[1];

     
    tx[0]=HMC5883L_Y_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    readings[1]= (int)rx[0]<<8|(int)rx[1];
     
    tx[0]=HMC5883L_Z_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    readings[2]= (int)rx[0]<<8|(int)rx[1];
    
}

int HMC5883L::getMx() {

    char tx[1];
    char rx[2];
    
    
    tx[0]=HMC5883L_X_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    return ((int)rx[0]<<8|(int)rx[1]);

}

int HMC5883L::getMy()
{
    char tx[1];
    char rx[2];

    tx[0]= HMC5883L_Y_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    return ((int)rx[0]<<8|(int)rx[1]);
    
    }
    
    int HMC5883L::getMz()
    
    {

    char tx[1];
    char rx[2];
    
    
    tx[0]=HMC5883L_Z_MSB;
    i2c_->write(HMC5883L_I2C_READ,tx,1);
    i2c_->read(HMC5883L_I2C_READ,rx,2);
    return ((int)rx[0]<<8|(int)rx[1]);
 
}


