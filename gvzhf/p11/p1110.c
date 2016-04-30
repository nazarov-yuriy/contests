/*
 * 1110.c
 *
 *  Created on: 25.02.2012
 *      Author: firefish
 */
#include <stdio.h>

int mpow(int x, int n, int m){
	int res = 1, i, l = x;
	for(i=0;i<11;i++){
		l=l%m;
		if(n&(1<<i))
			res*=l;
		l*=l;
		res=res%m;
	}
	return res%m;
}

int main(){
	int i,n,m,y,c=0;
	scanf("%d %d %d", &n, &m, &y);
	for(i=0;i<m;i++)
		if(mpow(i, n, m)==y){
			c++;
			printf("%d ", i);
		}
	if(c==0)
		printf("-1");
	return 0;
}

