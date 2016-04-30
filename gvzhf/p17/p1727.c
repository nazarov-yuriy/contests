/*
 * 1727.c
 *
 *  Created on: 29 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main(){
	int n,i,j,c=0,s=0,l;
	scanf("%d", &n);
	i=99998;
	while(s+45<n){
		int t = i;
		s+=t/10000; t=t%10000;
		s+=t/1000;  t=t%1000;
		s+=t/100;   t=t%100;
		s+=t/10;    t=t%10;
		s+=t;
		i--;
		c++;
	}
	printf("%d\n", c+1);
	for(j=99998;j>i;j--){
		printf("%d ", j);
	}
	n-=s;
	if(n>36)
		printf("%d9999", n-36);
	else if(n>27)
		printf("%d999", n-27);
	else if(n>18)
		printf("%d99", n-18);
	else if(n>9)
		printf("%d9", n-9);
	else
		printf("%d", n);
	return 0;
}

