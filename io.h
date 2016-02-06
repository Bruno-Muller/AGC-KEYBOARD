/* 
 * File:   io.h
 * Author: Bruno
 *
 * Created on 6 février 2016, 21:33
 */

#ifndef IO_H
#define	IO_H

#define SELECT              RC4
#define INT_KBD             RC5

#define select_assert()     SELECT = 0
#define select_disassert()  SELECT = 1

#define int_assert()        INT_KBD = 0
#define int_disassert()     INT_KBD = 1

void io_init();

#endif	/* IO_H */

