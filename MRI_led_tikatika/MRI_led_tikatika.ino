#include <MsTimer2.h>
#include <stdio.h>
#define LED 13
#define SW 1   // yet
#define DT 100 // ms: control cycle
#define BLINK_TIME 5000

static FILE uartout;

static int uart_putchar (char c, FILE *stream) {
    if (Serial.write(c) > 0) {
      return 0;
    } else {
      return -1;
    }
}

int t = 0; // counter for control cycle
void flash() {
  t++; 
  
  // LED blink
  static int t_led = 0; // counter for LED blink
  if (!t_led && digitalRead(SW)) {  // start
    printf("s%d\n", t * DT);
    t_led = 1;
  }
  if (t_led > BLINK_TIME) {         // end
    printf("e%d\n", t * DT);
    t_led = 0;
    digitalWrite(LED, LOW);
  }
  if (t_led) {                      // during blink
    static boolean output = HIGH;

    digitalWrite(LED, output);
    output = !output;
    t_led++;
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
  Serial.begin(9600);
  printf("c: %d ms, b: %d ms", DT, BLINK_TIME);
  
  MsTimer2::set(DT, flash); // 500ms period
  MsTimer2::start();
}

void loop() {
}
