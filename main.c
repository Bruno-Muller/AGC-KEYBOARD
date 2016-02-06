/* 
 * File:   main.c
 * Author: Bruno
 *
 * Created on 28 novembre 2015, 19:38
 */

#include <xc.h>

#include "bits.h"
#include "channel.h"
#include "conf.h"
#include "i2c.h"
#include "io.h"
#include "keyboard.h"

void init() {
    // CLOCK 16 MHz
    OSCCON = 0b01111000; // 4x PLL is disabled; 16 MHz HF; Clock determined by FOSC<2:0> in Configuration Word 1

    io_init();
    i2c_init();
    
    PEIE = 1;
    ei();
}

void key_pressed(unsigned key) {
    channel = CHANNEL_KBD;
    data_high = 0;
    data_low = key;
    key_pending = 1;
    int_assert();
}

int main(void) {
    init();

    unsigned char keys_state[] = {0x1F,0x1F,0x1F,0x1F};
    unsigned char key_mask, keys_read, key_index;
    unsigned char i, j;
    
    while(1) {

        for (i=0; i<4; i++) {
            
            // Set decoder address
            PORTC = (PORTC & ~0x0C) | ((i<<2) & 0x0C); 
            
            // Read keys
            select_assert();
            __delay_ms(2);
            keys_read = PORTA;
            keys_read = ((keys_read & 0x07) | ((keys_read & 0x30)>>1));
            select_disassert();
            
            // If at least one of the keys as changed
            if (keys_read != keys_state[i]) {
                
                // Test each keys
                for (j = 0; j<5; j++) {
                    
                    key_mask = 1<<j;
                    
                    // If the key state has changed and is pressed
                    if (((keys_state[i] & key_mask) != (keys_read & key_mask)) && ((keys_read & key_mask) == 0)) {
                        
                        // Compute key index
                        key_index = ((i<<3) | (j));
                        
                        // Throw interrupt to master
                        key_pressed(key_table[key_index]);
                        
                        // Wait until master has read the data
                        while (key_pending);
                    }     
                }
                
                // Set new keys state
                keys_state[i] = keys_read;
            }
        }
    }
}


