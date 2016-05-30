
/*
 * NAME
 *
 *   exec.c
 *
 * DESCRIPTION
 *
 *   This function sends a test pattern to the hardware UART
 *
 * PARAMETERS
 *
 *   None
 *
 * RETURN
 *
 *   Boolean status
 *
 * EXAMPLE
 *
 *   This program is not meant to be called by an operating system or other
 *   programs. Build and deploy to the target.
 *
 *  NOTES
 *
 *    Refactored from original to use a header file for the forward declaration
 *    of the bootstrap functions
 */

#include <stdint.h>
#include "bootstrap.h"
#include "systimer.h"

int notmain ( void )
{
  static rpi_sys_timer_t* rpiSystemTimer = (rpi_sys_timer_t*)RPI_SYSTIMER_BASE;
  volatile uint32_t ts;
  uint32_t counter = 0;

  // Initialize UART
  uart_init();

  // 100 Hz Cyclic Executive
  do {
      ts = rpiSystemTimer->counter_lo;
      hexstring(counter);
      counter++;
      counter %= 8;

      while( ( rpiSystemTimer->counter_lo - ts ) < 10000 ){
          /* Wait out remainder of frame */
      }
  } while(1);
}

/*
 * Copyright 2016 Chris Schulenberg christopher.s.schulenberg@gmail.com
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
