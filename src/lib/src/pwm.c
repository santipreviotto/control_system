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
/** \file pwm.c */
/* third party libs */
#include <avr/io.h>

/* local libs */
#include "../inc/pwm.h"

/* macro definition */


void PwmTimer1Init(PwmTimer1Mode_t PwmTimer1Mode) {
    switch (PwmTimer1Mode) {
        case FAST:
            TCCR1A &=~(1 << WGM10);
            TCCR1A |= (1 << WGM11);
            TCCR1B |= (1 << WGM12);
            TCCR1B |= (1 << WGM13);
            break;
        default:
            break;
    }
}

void PwmTimer1PowerOn(PwmTimer1Prescaler_t PwmTimer1Prescaler) {
    switch (PwmTimer1Prescaler) {
        case N1024:
            TCCR1B |= (1 << CS10);
            TCCR1B &=~(1 << CS11);
            TCCR1B |= (1 << CS12);
            break;
        default:
            break;
    }
}

void PwmPowerOff() {
}

void PwmSetFreq(uint32_t PwmFreq) {
}

void PwmSetDuty(uint8_t PwmDuty) {
}
