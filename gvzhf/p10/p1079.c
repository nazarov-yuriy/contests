/*
 * 1079.c
 *
 *  Created on: 22 Feb 2012
 *      Author: firefish
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cache[100000] = {0};

int res(int t){
	if(0==t) return 0;
	if(1==t) return 1;
	if(0==cache[t]){
		if(t%2==0){
			cache[t] = res(t/2);
		} else {
			cache[t] = res(t/2) + res(t/2+1);
		}
	}
	return cache[t];
}

int main(){
	int c, t, max, i;
	scanf("%d", &t);
	while(t){
		max = 0;
		for(i=0;i<=t;i++)
			if(res(i)>max)
				max = res(i);
		printf("%d\n", max);
		scanf("%d", &t);
	}
	return 0;
}

