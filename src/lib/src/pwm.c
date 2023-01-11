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
#define PERCENTMAX              100.0
#define CALCULEVALUE            2

volatile uint8_t PrescalerValue;
volatile uint32_t PwmFrequency;

static float FreqCalcule(uint32_t FreqValue, uint16_t PrescValue) {
    return ((float)(CPUFREQ) / (float)((FreqValue * CALCULEVALUE * PrescValue)));
}

void PwmInit(PwmMode_t PwmMode) {
    switch (PwmMode) {
        case PHASEANDFREQCORRECT:
            TCCR1A &=~(1 << WGM10);
            TCCR1A &=~(1 << WGM11);
            TCCR1B &=~(1 << WGM12);
            TCCR1B |= (1 << WGM13);
            break;
        default:
            break;
    }
}

void PwmPowerOn(PwmPrescaler_t PwmPrescaler) {
    switch (PwmPrescaler) {
        case N8:
            PrescalerValue = PRESC8;
            TCCR1B &=~(1 << CS10);
            TCCR1B |= (1 << CS11);
            TCCR1B &=~(1 << CS12);
            break;
        case NOFF:
            PrescalerValue = PRESCOFF;
            TCCR1B &=~(1 << CS10);
            TCCR1B &=~(1 << CS11);
            TCCR1B &=~(1 << CS12);
        default:
            PrescalerValue = PRESCOFF;
            break;
    }
}

void PwmPowerOff() {
}

void PwmSetFreq(uint32_t PwmFreq) {
    PwmFrequency = PwmFreq;
    TCNT1 = 0x0000;
    ICR1 = (uint16_t) FreqCalcule(PwmFrequency, PrescalerValue);
}

void PwmSetDuty(float PwmDuty) {
    TCCR1A &=~(1 << COM1A0);
    TCCR1A |= (1 << COM1A1);
    OCR1A = (uint16_t)((PwmDuty / PERCENTMAX) * FreqCalcule(PwmFrequency, PrescalerValue));
}


