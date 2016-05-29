/*
 * systimer.c
 *
 *  Created on: May 29, 2016
 *      Author: christopher.s.schulenberg@gmail.com
 *      Modified from: https://github.com/BrianSidebotham/arm-tutorial-rpi/blob/master/part-3/arm012/rpi-systimer.h
 */

#include <stdint.h>
#include "peripherals.h"
#include "systimer.h"

static rpi_sys_timer_t* rpiSystemTimer = (rpi_sys_timer_t*)RPI_SYSTIMER_BASE;

rpi_sys_timer_t* RPI_GetSystemTimer(void)
{
    return rpiSystemTimer;
}

void RPI_WaitMicroSeconds( uint32_t us )
{
    volatile uint32_t ts = rpiSystemTimer->counter_lo;

    while( ( rpiSystemTimer->counter_lo - ts ) < us )
    {
        /* BLANK */
    }
}

/*
 * Copyright (c) 2016 Chris Schulenberg christopher.s.schulenberg@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so,subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
