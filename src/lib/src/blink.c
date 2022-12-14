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
/** \file blink.c */
/* third party libs */
#include <avr/io.h>
#include <util/delay.h>

/* local libs */
#include "../inc/blink.h"

/* macro definition */
#define TIME_MS     100 /**< \brief Time for blink in milliseconds. */

/**
 *  \brief It's a blink function.
 */
void vBlink() {
    PORTB |= (1 << BLINKING_LED);
    _delay_ms(TIME_MS);
    PORTB &=~(1 << BLINKING_LED);
    _delay_ms(TIME_MS);
}
