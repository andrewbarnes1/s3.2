#include "mbed.h"

PwmOut red(D5);
PwmOut green(D9);
// Blue does not have PWM enabled

AnalogIn left(A0);
AnalogIn right(A1);

int main()
{
  red.period_ms(1);/* suitably fast 100Hz */

  while(1){
    /* ramp up from 0 to 100% */

    float redDuty;
    float greenDuty;

    redDuty = left.read();
    red.write(redDuty);
    wait_ms(30);

    greenDuty = right.read();
    green.write(greenDuty);
    wait_ms(30);

    /*
    // Triangle Wave
    for( duty=1.0 ; duty>0 ; duty-=0.01 ) {
      red.write(duty);
      wait_ms(30);
    }
    for(duty = 0; duty < 1.0; duty += 0.01) {
      red.write(duty);
      wait_ms(30);
    }
    */

    /*
    // Sawtooth wave
    for(duty = 0; duty < 1.0; duty += 0.01) {
      red.write(duty);
      wait_ms(30);
    }
    */
  }
}
