/* ifields.h */
/* Bullet-proof input fields for Microsoft (R) DOS and Windows
 *
 * Copyright 2010 Ankit Pati <ankitpati@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the  terms of the GNU Lesser General Public License as published by the  Free
 * Software Foundation; either version 3 of the License, or (at your option) any
 * later version.
 *
 * This  library is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You  should  have received a copy of the GNU Lesser  General  Public  License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef apIFIELDS_H
#define apIFIELDS_H

#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

long int getint(unsigned int len)
{
    char *s;
    unsigned int n=0;
    int c;
    int z=1;
    int k=0;
    long int rt;
    if((s=(char *)malloc(len+1))==NULL){
        cprintf("getint: Allocation Error!\r\n");
        exit(1);
    }
    putch(' ');
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(isdigit(c) && n<len){
            *(s+n++)=c;
            putch(c);
            continue;
        }
        if(!n){
            if(c=='-'){
                z=-1;
                putch('\b');
                putch('-');
                continue;
            }
            if(c=='+'){
                z=1;
                putch('\b');
                putch('+');
                continue;
            }
            if(c=='\b'){
                z=1;
                putch('\b');
                putch(' ');
                continue;
            }
        }
        if(c=='\b'){
            n--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        /* if(c!='\r' || !n) putch('\a'); */
    } while(c!='\r' || !n);
    *(s+n)='\0';
    rt=z*atol(s);
    free(s);
    for(;len-n;n++) putch(' ');
    return rt;
}

double getfl(unsigned int nlen, unsigned int flen)
{
    int c;
    int z=1;
    unsigned int n=0;
    unsigned int f=0;
    unsigned int d=0;
    int k=0;
    double rt;
    char *s;
    if((s=(char *)malloc((nlen+flen+2)))==NULL){
        cprintf("getfl: Allocation Error!\r\n");
        exit(1);
    }
    putch(' ');
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(!d){
            if(!n){
                if(c=='-'){
                    z=-1;
                    putch('\b');
                    putch('-');
                    continue;
                }
                if(c=='+'){
                    z=1;
                    putch('\b');
                    putch('+');
                    continue;
                }
                if(c=='\b'){
                    z=1;
                    putch('\b');
                    putch(' ');
                    continue;
                }
            }
            if(isdigit(c) && n<nlen){
                *(s+n++)=c;
                putch(c);
                continue;
            }
            if(c=='.'){
                d=1;
                *(s+n)=c;
                putch(c);
                continue;
            }
            if(c=='\b' && n){
                n--;
                putch('\b');
                putch(' ');
                putch('\b');
                continue;
            }
        }
        if(d){
            if(isdigit(c) && f<flen){
                *(s+n+d+f++)=c;
                putch(c);
                continue;
            }
            if(c=='\b'){
                if(f){
                    f--;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    continue;
                }
                else{
                    d=0;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    continue;
                }
            }
        }
        /* if(c!='\r' || (d?(n?0:!f):!n)) putch('\a'); */
    } while(c!='\r' || (d?(n?0:!f):!n));
    *(s+n+d+f)='\0';
    rt=z*atof(s);
    free(s);
    for(;nlen+flen+1-n-f-d;d++) putch(' ');
    return rt;
}

unsigned long int getuint(unsigned int len)
{
    char *s;
    unsigned int n=0;
    int c;
    int k=0;
    unsigned long int rt;
    if((s=(char *)malloc(len+1))==NULL){
        cprintf("getuint: Allocation Error!\r\n");
        exit(1);
    }
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(isdigit(c) && n<len){
            *(s+n++)=c;
            putch(c);
            continue;
        }
        if(c=='\b' && n){
            n--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        /* if(c!='\r' || !n) putch('\a'); */
    } while(c!='\r' || !n);
    *(s+n)='\0';
    rt=atol(s);
    free(s);
    for(;len-n;n++) putch(' ');
    return rt;
}

double getufl(unsigned int nlen, unsigned int flen)
{
    int c;
    unsigned int n=0;
    unsigned int f=0;
    unsigned int d=0;
    int k=0;
    double rt;
    char *s;
    if((s=(char *)malloc((nlen+flen+2)))==NULL){
        cprintf("getufl: Allocation Error!\r\n");
        exit(1);
    }
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(!d){
            if(isdigit(c) && n<nlen){
                *(s+n++)=c;
                putch(c);
                continue;
            }
            if(c=='.'){
                d=1;
                *(s+n)=c;
                putch(c);
                continue;
            }
            if(c=='\b' && n){
                n--;
                putch('\b');
                putch(' ');
                putch('\b');
                continue;
            }
        }
        if(d){
            if(isdigit(c) && f<flen){
                *(s+n+d+f++)=c;
                putch(c);
                continue;
            }
            if(c=='\b'){
                if(f){
                    f--;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    continue;
                }
                else{
                    d=0;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    continue;
                }
            }
        }
        /* if(c!='\r' || (d?(n?0:!f):!n)) putch('\a'); */
    } while(c!='\r' || (d?(n?0:!f):!n));
    *(s+n+d+f)='\0';
    rt=atof(s);
    free(s);
    for(;nlen+flen+1-n-f-d;d++) putch(' ');
    return rt;
}

char* getstr(char *buf, unsigned int len)
{
    unsigned int n=0;
    int c;
    int k=0;
    if(buf==NULL)
    if((buf=(char *)malloc(len+1))==NULL)
        return NULL;
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(isprint(c) && n<len){
            *(buf+n++)=c;
            putch(c);
            continue;
        }
        if(c=='\b' && n){
            n--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        /* if(c!='\r') putch('\a'); */
    } while(c!='\r' || !n);
    *(buf+n)='\0';
    for(;len-n;n++) putch(' ');
    return buf;
}

unsigned long int getnumpw(unsigned int len)
{
    char *s;
    unsigned int n=0;
    int c;
    int k=0;
    unsigned long int rt;
    if((s=(char *)malloc(len+1))==NULL){
        cprintf("getnumpw: Allocation Error!\r\n");
        exit(1);
    }
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(isdigit(c) && n<len){
            *(s+n++)=c;
            putch('*');
            continue;
        }
        if(c=='\b' && n){
            n--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        /* if(c!='\r' || !n) putch('\a'); */
    } while(c!='\r' || !n);
    *(s+n)='\0';
    rt=atol(s);
    free(s);
    for(;len-n;n++) putch(' ');
    return rt;
}

char* getstrpw(char *buf, unsigned int len)
{
    unsigned int n=0;
    int c;
    int k=0;
    if(buf==NULL)
    if((buf=(char *)malloc(len+1))==NULL)
        return NULL;
    do{
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(isprint(c) && n<len){
            *(buf+n++)=c;
            putch('*');
            continue;
        }
        if(c=='\b' && n){
            n--;
            putch('\b');
            putch(' ');
            putch('\b');
            continue;
        }
        /* if(c!='\r') putch('\a'); */
    } while(c!='\r' || !n);
    *(buf+n)='\0';
    for(;len-n;n++) putch(' ');
    return buf;
}

int getctrl()
{
    int c;
    int k=0;
    for(;;){
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            k=0;
            /* putch('\a'); */
            continue;
        }
        if(iscntrl(c)) return c;
        /* putch('\a'); */
    }
}

int getsysk()
{
    int c;
    int k=0;
    for(;;){
        c=getch();
        if(!c){
            k=1;
            continue;
        }
        if(k){
            return c;
        }
        /* putch('\a'); */
    }
}

#endif
/* end of ifields.h */
