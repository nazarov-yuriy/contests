/*
 * 1209.c
 *
 *  Created on: 21.02.2012
 *      Author: firefish
 */

#include <math.h>

int main(){
	long long int N, n, q;
	scanf("%lld", &N);
	for(;N-->0;){
	scanf("%lld", &n);
	q = sqrt(n*2);
	if((q*(q-1)/2 == n-1)||((q+1)*(q+2)/2 == n-1)||(q*(q+1)/2 == n-1)||(n==1)||(n==2))
		printf("1 ");
	else
		printf("0 ");}
	return 0;
}

