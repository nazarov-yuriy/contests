/*
 * 1330.c
 *
 *  Created on: 28 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int k[10011];

int main(){
	int n,q,tk,i,j,l;
	scanf("%d", &n);
	k[0]=0;
	for(l=0;l<n;l++){
		scanf("%d", &tk);
		k[l+1]=k[l]+tk;
	}
	scanf("%d", &q);
	for(l=0;l<q;l++){
		scanf("%d", &i);
		scanf("%d", &j);
		printf("%d\n", k[j]-k[i-1]);
	}
	return 0;
}

