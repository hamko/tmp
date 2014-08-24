#include <Arduino.h>
#include <stdio.h>

FILE uartout;

int uart_putchar (char c, FILE *stream) {
    if (Serial.write(c) > 0) {
      return 0;
    } else {
      return -1;
    }
}

