/*
 * 1582.c
 *
 *  Created on: 24.02.2012
 *      Author: firefish
 */
#include <stdio.h>

int main(){
	float k1, k2, k3, r;
	scanf("%f %f %f", &k1, &k2, &k3);
	r = 1000.0 / (1.0/k1 + 1.0/k2 + 1.0/k3);
	printf("%.0f", r);
	return 0;
}

