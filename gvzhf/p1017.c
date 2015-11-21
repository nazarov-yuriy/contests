/*
 * 1017.c
 *
 *  Created on: 26 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

long long int cache[35][500] = {0};

long long int rec(int c, int n){
	long long int ret = cache[c][n];
	int rn;
	if (ret)
		return ret;
	for(rn=n-c; rn>0;rn-=c){
		ret+=rec(c-1, rn);
	}
	cache[c][n] = ret;
	return ret;
}

int main(){
	int i, n;
	long long int summ = 0;
	scanf("%d", &n);
	for(i=0;i<500;i++)
		cache[1][i]=1;
	for(i=2;i<35;i++)
		summ+=rec(i, n);
	printf("%lld", summ);
	return 0;
}

