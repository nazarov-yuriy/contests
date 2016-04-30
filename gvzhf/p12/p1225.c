/*
 * 1225.c
 *
 *  Created on: 23 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

long long int bc[50] = {0, 0};
long long int bk[50] = {1, 0};
long long int cb[50] = {1, 0};
long long int ck[50] = {1, 0};
long long int kb[50] = {1, 0};
long long int kc[50] = {0, 0};

int main(){
	long long int i, n;
	scanf("%lld", &n);
	if (1==n){
		printf("2");
	} else if (2==n) {
		printf("2");
	} else {
		for(i=1;i<n-2;i++){
			bc[i] = ck[i-1];
			bk[i] = kb[i-1]+kc[i-1];
			cb[i] = bc[i-1]+bk[i-1];
			ck[i] = kb[i-1]+kc[i-1];
			kb[i] = bc[i-1]+bk[i-1];
			kc[i] = cb[i-1];
		}
		printf("%lld", bc[n-3]+bk[n-3]+cb[n-3]+ck[n-3]+kb[n-3]+kc[n-3]);
	}
	return 0;
}

