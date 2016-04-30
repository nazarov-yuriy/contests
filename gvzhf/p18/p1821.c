/*
 * 1821.c
 *
 *  Created on: 25.02.2012
 *      Author: firefish
 */
#include <stdio.h>
#include <string.h>

char b[101][30];
char a[101][30];
int  f[101];
int  ti[101];

int main(){
	int n, i, j, m, mm, s, sm, d, dm, t, min, rn;
	char c[30];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s %d:%d.%d", &b[i], &m, &s, &d);
		f[i] = d+10*s+600*m+300*i;
		ti[i] = d+10*s+600*m;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(f[i]>f[j]){
				strcpy(c, b[i]);
				strcpy(b[i], b[j]);
				strcpy(b[j], c);
				t=f[i];
				f[i]=f[j];
				f[j]=t;
				t=ti[i];
				ti[i]=ti[j];
				ti[j]=t;
			}
	min = 100500;
	rn=0;
	for(i=0;i<n;i++){
		if(ti[i]<min){
			min = ti[i];
			strcpy(a[rn++], b[i]);
		}
	}
	for(i=0;i<rn-1;i++)
		for(j=i+1;j<rn;j++)
			if(strcmp(a[i], a[j])>0){
				strcpy(c, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], c);
			}
	printf("%d\n", rn);
	for(i=0;i<rn;i++)
		printf("%s\n", a[i]);
	return 0;
}

