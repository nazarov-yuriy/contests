/*
 * 1756.c
 *
 *  Created on: 28 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main(){
	int m,d1,d2,i,c,d;
	scanf("%d %d %d", &m, &d1, &d2);
	for(i=0;i<((m*d1)%d2);i++)
		printf("%d ", (m*d1)/d2+1);
	for(i=((m*d1)%d2);i<d2;i++)
		printf("%d ", (m*d1)/d2);
	return 0;
}

