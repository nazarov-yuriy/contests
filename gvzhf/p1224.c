/*
 * 1224.c
 *
 *  Created on: 28 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main(){
	long long int n,m;
	scanf("%lld %lld",&n, &m);
	if(m<n)
		printf("%lld", 1+2*(m-1));
	else
		printf("%lld", 2*(n-1));
	return 0;
}

