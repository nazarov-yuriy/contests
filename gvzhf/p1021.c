/*
 * 1021.c
 *
 *  Created on: 23 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int f[50100];
int s[50100];

int main(){
	int fc, sc, fp, sp;

	scanf("%d",&fc);
	for(fp=0;fp<fc;fp++)
		scanf("%d", &f[fp]);

	scanf("%d", &sc);
	for(sp=0;sp<sc;sp++)
			scanf("%d", &s[sp]);

	fp=0; sp=0;
	while((fp<fc)&&(sp<sc)){
		if(f[fp]+s[sp] == 10000){
			printf("YES");
			return 0;
		}
		if(f[fp]+s[sp] < 10000)
			fp++;
		if(f[fp]+s[sp] > 10000)
			sp++;
	}
	printf("NO");
	return 0;
}

