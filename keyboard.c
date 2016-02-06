/*
 * File:   keyboard.c
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:37
 */

#include "keyboard.h"

// Channel 015
#define KEY_ZERO    0b00010000
#define KEY_ONE     0b00000001 
#define KEY_TWO     0b00000010 
#define KEY_THREE   0b00000011 
#define KEY_FOUR    0b00000100 
#define KEY_FIVE    0b00000101
#define KEY_SIX     0b00000110 
#define KEY_SEVEN   0b00000111 
#define KEY_EIGHT   0b00001000 
#define KEY_NINE    0b00001001 
#define KEY_VERB    0b00010001 
#define KEY_RESET   0b00010010 
#define KEY_KEY_REL 0b00011001 
#define KEY_PLUS    0b00011010 
#define KEY_MINUS   0b00011011 
#define KEY_ENTER   0b00011100 
#define KEY_CLEAR   0b00011110 
#define KEY_NOUN    0b00011111
#define KEY_NULL    0

// Channel 032
// KEY_PRO !bit14

const unsigned char const key_table[] = {
    KEY_ZERO, KEY_ONE, KEY_TWO, KEY_THREE, KEY_KEY_REL, KEY_NULL, KEY_NULL, KEY_NULL,
    KEY_MINUS, KEY_FOUR, KEY_FIVE, KEY_SIX, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL,
    KEY_PLUS, KEY_SEVEN, KEY_EIGHT, KEY_NINE, KEY_CLEAR, KEY_NULL, KEY_NULL, KEY_NULL,
    KEY_VERB, KEY_NOUN, KEY_RESET, KEY_ENTER, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL      
};

unsigned char key_pending = 0;

