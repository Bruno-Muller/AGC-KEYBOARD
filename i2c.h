/* 
 * File:   i2c.h
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:42
 */

#ifndef I2C_H
#define	I2C_H

#define channel     i2c_buffer[0]
#define data_high   i2c_buffer[1]
#define data_low    i2c_buffer[2]

extern unsigned char i2c_buffer[3];

void i2c_init();
void i2c_interrupt_handler();

#endif	/* I2C_H */

