/*
 * 1788.c
 *
 *  Created on: 25.02.2012
 *      Author: firefish
 */
#include <stdio.h>

int b[110];
int g[110];

void sort(int *a, int n){
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}

int main(){
	int bn,gn,i,bs=0,gs=0,min;
	scanf("%d %d", &gn, &bn);
	for(i=0;i<gn;i++){
		scanf("%d", &g[i]);
		gs+=g[i];
	}
	for(i=0;i<bn;i++){
		scanf("%d", &b[i]);
		bs+=b[i];
	}
	sort(b, bn);
	sort(g, gn);
	min=gs;
	for(i=0;(i<bn)&&(i<gn);i++){
		gs-=g[i];
		bs-=b[i];
		if((gs+(i+1)*bs)<min)
			min = (gs+(i+1)*bs);
	}
	printf("%d", min);
	return 0;
}

