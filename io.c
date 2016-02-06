/*
 * File:   io.c
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:32
 */


#include <xc.h>

#include "io.h"

void io_init() {
    // Disable analog pins
    ANSELA = 0x00;
    ANSELC = 0x00;

    // LATCH
    LATA = 0;
    LATC = 0;

    // PORT
    PORTA = 0;
    PORTC = 0b00110011;

    // TRIS
    TRISA = 0b11111111;
    TRISC = 0b11000011;
}