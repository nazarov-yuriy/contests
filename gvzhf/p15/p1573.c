/*
 * 1573.c
 *
 *  Created on: 24 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main() {
	int i, b, r, y, k, res = 1;
	char c[10];
	scanf("%d %d %d %d", &b, &r, &y, &k);
	for (i = 0; i < k; i++) {
		scanf("%s", c);
		if ('B' == c[0])
			res *= b;
		if ('R' == c[0])
			res *= r;
		if ('Y' == c[0])
			res *= y;
	}
	printf("%d", res);
	return 0;
}

