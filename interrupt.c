/*
 * File:   interrupt.c
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:45
 */

#include <xc.h>

#include "i2c.h"

void interrupt interrupt_handler() {
    if (SSP1IF == 1) {
        SSP1IF = 0; // Clear interrupt flag
        i2c_interrupt_handler();
    }
}
