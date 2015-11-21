/*
 * 1048.c
 *
 *  Created on: 26 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

char arr[1000010];

int main(){
	int n, i, a, b;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %d", &a, &b);
		arr[i]=a+b;
	}
	for(i=n-1;i>0;i--){
		arr[i-1]+=arr[i]/10;
		arr[i]=arr[i]%10;
	}
	if(arr[0]>10){
		printf("%d", arr[0]/10);
		arr[0]=arr[0]%10;
	}
	for(i=0;i<n;i++){
		printf("%d", arr[i]);
	}
	return 0;
}

