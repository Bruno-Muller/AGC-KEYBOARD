/*
 * File:   i2c.c
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:41
 */


#include "i2c.h"

#include "io.h"
#include "keyboard.h"

#include <xc.h>

#define I2C_KBD_ADDRESS    0x11

#define I2C_FRAME_START 0
#define I2C_FRAME_END   2

#define I2C_FRAME_MASK  0x3F

unsigned char i2c_buffer[3];

void i2c_init() {
    // TRIS
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;

    SSP1ADD = I2C_KBD_ADDRESS<<1;
    //SSPMSK = 0xFF;

    SSP1STATbits.SMP = 0; // Slew rate control enabled for high speed mode (400 kHz)
    //SSPSTATbits.SMP = 1; // Slew Rate Control (limiting) disabled. Operating in I2C Standard mode (100 kHz and 1 MHz).
    SSP1STATbits.CKE = 0; // Disable SMBus specific inputs
    SSP1CON1bits.CKP = 1; // Release clock stretch
    SSP1CON1bits.SSPM = 0b0110; // I2C Slave mode, 7-bit address
    SSP1CON2bits.GCEN = 0; // General call address disabled
    SSP1CON1bits.SSPEN = 1; // Enables the serial port and configures the SDA and SCL pins as serial port pins 
    SSP1IE = 1;
}

void i2c_interrupt_handler() {
    static unsigned char i = 0;
    unsigned char temp = SSPBUF;

    // ADDRESS
    if (SSPSTATbits.D_nA == 0) {
        i = I2C_FRAME_START;
    }

    // DATA READ (slave writes to master)
    if (SSPSTATbits.R_nW == 1) {
        SSPBUF = i2c_buffer[i]; // 
        SSPCONbits.CKP = 1;
    }
    // DATA WRITE (slave reads from master)
    else {
    }

    if (i == I2C_FRAME_END) {
        int_disassert();
        key_pending = 0;
    }

    i++;
}
