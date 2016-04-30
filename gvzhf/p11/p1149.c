/*
 * 1149.c
 *
 *  Created on: 29 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int n;

void rec1(int ln){
	int i=0;
	for(i=1;i<ln;i++){
		printf("sin(%d%c", i, (i%2)?'-':'+');
	}
	printf("sin(%d)", ln);
	for(i=ln-1;i>0;i--){
		printf(")");
	}
}

void rec(int i){
	if(i<n){
		printf("(");
		rec(i+1);
		printf(")");
		rec1(n+1-i);
		printf("+%d", i);
	} else {
		rec1(n+1-i);
		printf("+%d", i);
	}
}

int main(){
	scanf("%d", &n);
	rec(1);
	return 0;
}

