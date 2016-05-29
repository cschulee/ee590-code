/*
 * systimer.h
 *
 *  Created on: May 28, 2016
 *      Author: christopher.s.schulenberg@gmail.com
 *      Modified from: https://github.com/BrianSidebotham/arm-tutorial-rpi/blob/master/part-3/arm012/rpi-systimer.h
 *
 */

#ifndef SYSTIMER_H_
#define SYSTIMER_H_

#include <stdint.h>
#include "peripherals.h"

typedef struct {
    volatile uint32_t control_status;
    volatile uint32_t counter_lo;
    volatile uint32_t counter_hi;
    volatile uint32_t compare0;
    volatile uint32_t compare1;
    volatile uint32_t compare2;
    volatile uint32_t compare3;
    } rpi_sys_timer_t;

extern rpi_sys_timer_t* RPI_GetSystemTimer(void);
extern void RPI_WaitMicroSeconds( uint32_t us );

#endif /* SYSTIMER_H_ */

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
