#ifndef __PRINTF_WRAPPER_H_INCLUDED__
#define __PRINTF_WRAPPER_H_INCLUDED__

#include <stdio.h>

extern FILE uartout;
extern int uart_putchar (char c, FILE *stream);

#endif 
