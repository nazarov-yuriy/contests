/*
 * 1005.c
 *
 *  Created on: 20 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main(){
	int i, j, n, r, min;
	int arr[20];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	min = +100500*20;
	for(i=0; i<(1<<n);i++){
		r = 0;
		for(j=0;j<n;j++)
			r += (i&(1<<j))?arr[j]:-arr[j];
		if(abs(r)<abs(min))
			min = r;
	}
	printf("%d", abs(min));
}
