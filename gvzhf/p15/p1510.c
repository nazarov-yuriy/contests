/*
 * 1510.c
 *
 *  Created on: 23 Feb 2012
 *      Author: firefish
 */

#include <stdio.h>

int arr[500100];

int main(){
	int n, i, j, b, l, d;
	unsigned int mask = 0x80000000;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	d = 0;
	for(j=30;j>=0;j--){
		b=0;
		l=0;
		for(i=0;i<n;i++){
			if(arr[i]>=(d|(1<<j)))
				b++;
			else
				l++;
		}
		//printf("%d %d\n", b, l);
		if(b>l)
			d|=1<<j;
	}
	printf("%d", d);
	return 0;
}

