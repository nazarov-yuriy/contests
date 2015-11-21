/*
 * 1786.c
 *
 *  Created on: 21.02.2012
 *      Author: firefish
 */

#include <stdio.h>
#include <string.h>

int delta(char *c) {
	int res = 0;
	if (c[0] != 'S') {
		res++;
		if ((c[0] != 's')&&(c[0]>'Z'))
			res++;
	}
	if (c[1] != 'a') {
		res++;
		if ((c[1] != 'A')&&(c[1]<'a'))
			res++;
	}
	if (c[2] != 'n') {
		res++;
		if ((c[2] != 'N')&&(c[2]<'a'))
			res++;
	}
	if (c[3] != 'd') {
		res++;
		if ((c[3] != 'D')&&(c[3]<'a'))
			res++;
	}
	if (c[4] != 'r') {
		res++;
		if ((c[4] != 'R')&&(c[4]<'a'))
			res++;
	}
	if (c[5] != 'o') {
		res++;
		if ((c[5] != 'O')&&(c[5]<'a'))
			res++;
	}
	return res;
}

int main() {
	int i, res = 12;
	char str[250];
	gets(str);
	for(i=0;i<strlen(str)-5;i++){
		if(res>delta(&str[i]))
			res=delta(&str[i]);
	}
	printf("%d", res*5);
}

