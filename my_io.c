//
// Created by choug on 11/7/2023.
//
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "my_io.h"
//#include <errno.h>

unsigned char * uart = (unsigned char *)0x10000000;
void my_putchar(char c) {
	*uart = c;
	return;
}

void my_print(const char * str) {
	while(*str != '\0') {
		my_putchar(*str);
		str++;
	}
	return;
}

char strs[128]; // large enough for an int even on 64-bit, Moved to global scope

//
//#if defined(__WATCOMC__) && __WATCOMC__ <= 1100
//#define FIXCONST	__based(__segname("CONST2"))
//#else
//#define FIXCONST
//#endif

char *ulltoa(uint64_t value, char *buf) {
    int radix = 10;
	char			tmp[64 + 1];		/* Lowest radix is 2, so 64-bits plus a null */
	char			*p1 = tmp, *p2;
	static const char  xlat[] = "0123456789abcdefghijklmnopqrstuvwxyz";



	do {
		*p1++ = xlat[value % (unsigned)radix];
	} while((value /= (unsigned)radix));

	for(p2 = buf; p1 != tmp; *p2++ = *--p1) {
		/* nothing to do */
	}
	*p2 = '\0';

	return buf;
}



void my_print_with_long_long(const char * str, unsigned long long num) {
	while(*str != '\0') {
		my_putchar(*str);
		str++;
	}
    // print num
    char *ch1_ptr = ulltoa(num, strs);
    while (*ch1_ptr != '\0') {
        my_putchar(*ch1_ptr);
        ch1_ptr++;
    }



	return;
}





