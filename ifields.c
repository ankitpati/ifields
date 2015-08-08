/* ifields.c */
/* Demonstration of ifields.h
 *
 * Copyright 2010 Ankit Pati <ankitpati@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation;  either version 3 of the License, or (at your option)  any  later
 * version.
 *
 * This  program is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR  A  PARTICULAR  PURPOSE.  See the GNU General  Public  License  for  more
 * details.
 *
 * You should have received a copy of the GNU General Public License along  with
 * this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * The GPL v3 text can be found at <./gpl.txt>.
 */

#include <string.h>
#include <conio.h>
#include "ifields.h"

int main()
{
    unsigned long ul1, ul2;
    long l1, l2;
    double ud1, ud2, d1, d2;
    char c1[11], c2[11];
    for(;;){
        cprintf("Enter two +ve integers to find the sum.\n\r");
        ul1=getuint(5);
        putch('\n'); putch('\r');
        ul2=getuint(5);
        putch('\n'); putch('\r');
        cprintf("The sum is %ld.\n\n\r", (ul1+ul2));
        cprintf("Enter two integers to find the sum.\n\r");
        l1=getint(5);
        putch('\n'); putch('\r');
        l2=getint(5);
        putch('\n'); putch('\r');
        cprintf("The sum is %ld.\n\n\r", (l1+l2));
        cprintf("Enter two +ve floats to find the sum.\n\r");
        ud1=getufl(5, 5);
        putch('\n'); putch('\r');
        ud2=getufl(5, 5);
        putch('\n'); putch('\r');
        cprintf("The sum is %f.\n\n\r", (ud1+ud2));
        cprintf("Enter two floats to find the sum.\n\r");
        d1=getfl(5, 5);
        putch('\n'); putch('\r');
        d2=getfl(5, 5);
        putch('\n'); putch('\r');
        cprintf("The sum is %f.\n\n\r", (d1+d2));
        cprintf("Enter two strings to concatenate them.\n\r");
        getstr(c1, 10);
        putch('\n'); putch('\r');
        getstr(c2, 10);
        putch('\n'); putch('\r');
        if(!c1 || !c2){
            cprintf("Allocation Error!\n\rCore dumped!\n\r");
            exit(1);
        }
        cprintf("The concatenate is %s%s.\n\n\r", c1, c2);
        cprintf("Enter a numeric password.\n\r");
        getnumpw(5)==43 ?
            cprintf("\n\rCorrect Password!\n\n\r") :
            cprintf("\n\rIncorrect Password!\n\n\r");
        cprintf("Enter a password.\n\r");
        !strcmp(getstrpw(c1, 10), "password") ?
            cprintf("\n\rCorrect Password!\n\n\r") :
            cprintf("\n\rIncorrect Password!\n\n\r");
        cprintf("Press control character.\n\r");
        cprintf("Code in Character Set: %d\n\n\r", getctrl());
        cprintf("Press system key.\n\r");
        cprintf("Code in Character Set: 0, %d\n\n\r", getsysk());
        cprintf("Enter Space to continue, anything else to terminate.\n\r");
        if(getch()!=' ') break;
        putch('\n'); putch('\r');
    }
    return 0;
}
/* end of ifields.c */
