/* 
 * File:   bits.h
 * Author: Bruno
 *
 * Created on 6 f�vrier 2016, 21:40
 */

#ifndef BITS_H
#define	BITS_H

#define testbit(var, bit) ((var) & (1 <<(bit)))
#define setbit(var, bit) ((var) |= (1 << (bit)))
#define clrbit(var, bit) ((var) &= ~(1 << (bit)))

#endif	/* BITS_H */

