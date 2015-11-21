/*
 * 1009.c
 *
 *  Created on: 20 Feb 2012
 *      Author: firefish
 */

#include <stdio.h>

unsigned long long int pow_m(int k, int n){
	unsigned long long int r = 1;
	for(;n-->0;)
		r*=k;
	return r;
}

unsigned long long int res(int n, int k){
	if (0 == n) { return 1; }
	if (1 == n) { return k; }
	if (2 == n) { return k*k-1; }
	if (3 == n) { return k*k*k - 2*k + 1; }
	if (4 == n) { return k*k*k*k - pow_m(k, n-2) - (k-1)*k - (k-1)*k; }
	if (5 == n) { return pow_m(k, n) - pow_m(k, n-2) - (k-1)*pow_m(k, n-3) - res(n-4, k)*(k-1)*k - res(n-3, k)*(k-1) ; }
	if (6 <= n) {
		unsigned long long int r = 0, i;
		for(i=0;i<(n-2);i++)
			r += res(i, k)*(k-1)*pow_m(k, n-3-i);
		return pow_m(k, n) - pow_m(k, n-2) - r; }
}

int main()
{
	unsigned long long int n, k, i, j;
	scanf("%lld %lld", &n, &k);

	//for(n = 2; n < 9; n++){
		//for(k = 2; k < 11; k++){
			printf("%lld", (k-1)*res(n-1, k));
		//}
		//printf("\n");
	//}
	return 0;
}
