//I2C_eeprom.h
#include "types.h"
void I2C_eeprom_bytewrite(u8 SlaveAddr, u8 wBuffAddr, u8 data);
u8 I2C_eeprom_byteread(u8 SlaveAddr, u8 ReadBuffAddr);
void i2c_eeprm_pagewrite(u8 SlaveAddr, u8 wBuffAddr, u8 *p, u8 nbytes);
void i2c_eeprom_seqread(u8 SlaveAddr, u8 rBuffSAddr, u8 *p, u8 nbytes);
