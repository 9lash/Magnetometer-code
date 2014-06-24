#ifdef HMC5883L_H
#define HMC5883L_H

#include "mbed.h"

#define HMC5883L_I2C_ADDRESS 0x1E
#define HMC5883L_I2C_READ    0x3C
#define HMC5883L_I2C_WRITE   0x3D

// Values Config A
#define HMC5883L_0_75_HZ_NORMAL   0x00
#define HMC5883L_0_75_HZ_POSITVE  0x01
#define HMC5883L_0_75_HZ_NEGATIVE 0x02

#define HMC5883L_3_HZ_NORMAL      0x08
#define HMC5883L_3_HZ_POSITVE     0x09
#define HMC5883L_3_HZ_NEGATIVE    0x0A

#define HMC5883L_15_HZ_NORMAL     0x10 // Default value of CRA
#define HMC5883L_15_HZ_POSITVE    0x11
#define HMC5883L_15_HZ_NEGATIVE   0x12

#define HMC5883L_75_HZ_NORMAL     0x00
#define HMC5883L_75_HZ_POSITVE    0x01
#define HMC5883L_75_HZ_NEGATIVE   0x02




// values Config B
#define HMC5883L_0_88GA      0x00
#define HMC5883L_1_33GA      0x20     // Default value of CRB      
#define HMC5883L_1_9GA       0x40       
#define HMC5883L_2_5GA       0x60         
#define HMC5883L_4_0GA       0x80      
#define HMC5883L_4_7GA       0xA0         
#define HMC5883L_5_6GA       0xC0        
#define HMC5883L_8_1GA       0xE0

//Values MODE
#define HMC5883L_CONTINUOUS   0x00
#define HMC5883L_SINGLE       0x01 // According to the Honeywell HMC5833L datasheet the default values for the MODE register is the Single measurement- 0x01//
#define HMC5883L_IDLE         0x02
#define HMC5883L_SLEEP        0x03


#define HMC5883L_CONFIG_A     0x00
#define HMC5883L_CONFIG_B     0x01
#define HMC5883L_MODE         0x02
#define HMC5883L_X_MSB        0x03
#define HMC5883L_X_LSB        0x04
#define HMC5883L_Z_MSB        0x05
#define HMC5883L_Z_LSB        0x06
#define HMC5883L_Y_MSB        0x07
#define HMC5883L_Y_LSB        0x08
#define HMC5883L_STATUS       0x09
#define HMC5883L_IDENT_A      0x0A
#define HMC5883L_IDENT_B      0x0B
#define HMC5883L_IDENT_C      0x0C




/**
 * Honeywell HMC5843 digital compass.
 */
class HMC5883L {

public:

    /**
     * Constructor.
     *
     * @param sda mbed pin to use for SDA line of I2C interface.
     * @param scl mbed pin to use for SCL line of I2C interface.
     */
    HMC5883L(PinName sda, PinName scl);

        
     /**
     * Enter into sleep mode.
     *
     */
    void setSleepMode();
    
       
     /**
     * Set Device in Default Mode.
     * HMC5883L_CONTINUOUS, HMC5883L_10HZ_NORMAL HMC5883L_1_3GA
     */
    void setDefault();
    
   
    /**
     * Read the memory location on the device which contains the address.
     *
     * @param Pointer to a buffer to hold the address value
     * Expected     H, 4 and 3.
     */
    void getAddress(char * address);


    
    /**
     * Set the operation mode.
     *
     * @param mode 0x00 -> Continuous
     *             0x01 -> Single
     *             0x02 -> Idle
     * @param ConfigA values
    * @param ConfigB values 
     */
    void setOpMode(int mode, int ConfigA, int ConfigB);
    
     /**
     * Write to  on the device.
     *
     * @param address Address to write to.
     * @param data Data to write.
     */
    
    void write(int address, int data);

     /**
     * Get the output of all three axes.
     *
     * @param Pointer to a buffer to hold the magnetics value for the
     *        x-axis, y-axis and z-axis [in that order].
     */
    void readData(int* readings);
    
    /**
     * Get the output of X axis.
     *
     * @return x-axis magnetic value
     */
    int getMx();
    
    /**
     * Get the output of Y axis.
     *
     * @return y-axis magnetic value
     */
    int getMy();
    
    /**
     * Get the output of Z axis.
     *
     * @return z-axis magnetic value
     */
    int getMz();
   
    
    /**
     * Get the current operation mode.
     *
     * @return Status register values
     */
    int getStatus(void);

  

    I2C* i2c_;

   

};

#endif /* HMC5883L_H */
