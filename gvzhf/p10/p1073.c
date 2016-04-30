/*
 * 1073.c
 *
 *  Created on: 20 Mar 2012
 *      Author: firefish
 */
#pragma comment(linker, "/STACK:16777216")
#include <stdio.h>

int cache[60001];

int fn(int c){
	int res=c,i,t;
	t=cache[c];
	if (t>=0)
		return t;
	for(i=1;i*i<=c;i++){
		t = fn(c-i*i)+1;
		if ( t<res )
			res = t;
	}
	cache[c] = res;
	return res;
}

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0;i<60001;i++){
		cache[i] = -i;
	}
	printf("%d", fn(n));
}

