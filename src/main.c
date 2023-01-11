/* Copyright (C) 2022  Santiago Previotto
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
/** \file main.c */
/* third party libs */
#include <avr/io.h>
#include <avr/interrupt.h>
/* local libs */
#include "lib/inc/pwm.h"

/**
 *	\brief Program entrypoint.
 */
int main() {
    /*
    DDRB |= (1 << DDB5);
    cli();
    TCCR1A &=~(1 << WGM10);
    TCCR1A &=~(1 << WGM11);
    TCCR1B &=~(1 << WGM12);
    TCCR1B |= (1 << WGM13);
   
    TCNT1 = 0x0000;
    ICR1 = 10000;
    TCCR1A &=~(1 << COM1A0);
    TCCR1A |= (1 << COM1A1);
    OCR1A = 1000;
    sei();
    TCCR1B &=~(1 << CS10);
    TCCR1B |= (1 << CS11);
    TCCR1B &=~(1 << CS12);
    */
    DDRB |= (1 << DDB5); 
    cli();
    PwmInit(PHASEANDFREQCORRECT);
    sei();
    PwmPowerOn(N8);
    PwmSetFreq(100);
    PwmSetDuty(5.8);
    while (1) {
    }
    return 0;
}
