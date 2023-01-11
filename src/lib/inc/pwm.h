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
/** \file pwm.h */
#ifndef SRC_LIB_INC_PWM_H_
#define SRC_LIB_INC_PWM_H_

typedef enum {
    NORMAL,
    CTC,
    FAST,
    PHASECORRECT,
    PHASEANDFREQCORRECT,
} PwmTimer1Mode_t;

typedef enum {
    NOFF,
    N1,
    N8,
    N64,
    N256,
    N1024,
} PwmTimer1Prescaler_t;
/**
 *  \brief  Function to initializate
            PWM feature.
 */
void PwmTimer1Init(PwmTimer1Mode_t PwmTimer1Mode);
void PwmTimer1PowerOn(PwmTimer1Prescaler_t PwmTimer1Prescaler);
void PwmPowerOff();
void PwmSetFreq(uint32_t PwmFreq);
void PwmSetDuty(uint8_t PwmDuty);

#endif  /* SRC_LIB_INC_PWM_H_ */
