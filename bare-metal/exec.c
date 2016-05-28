
/*
 * uart05.c
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
 *   This function is not meant to be called by an operating system or other
 *   programs
 *
 *  NOTES
 *
 *    Refactored from original to use a header file for the forward declaration
 *    of the bootstrap functions
 */

#include "bootstrap.h"

//------------------------------------------------------------------------
int notmain ( void )
{
    uart_init();
    hexstring(0x12345678);
    hexstring(GETPC());
    hexstring(GETCPSR());
    return(0);
}

/*
 * Original work Copyright (c) 2014 David Welch dwelch@dwelch.com
 * Modified work Copyright 2016 Chris Schulenberg christopher.s.schulenberg@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies ofthe Software, and to permit persons to whom the Software is
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
