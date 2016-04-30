/*
 * 1868.c
 *
 *  Created on: 25.02.2012
 *      Author: firefish
 */
#include <stdio.h>
#include <string.h>

char g[4][35];
char s[4][35];
char b[4][35];

int main(){
	int i,j,jn,n,t,max=0,count=0;
	char c[35],p[35];
	for(i=0;i<4;i++)
		scanf("%s", g[i]);
	for(i=0;i<4;i++)
		scanf("%s", s[i]);
	for(i=0;i<4;i++)
		scanf("%s", b[i]);
	scanf("%d", &n);
	for(i=0;i<n;i++){
		int l=0;
		scanf("%d", &jn);
		for(j=0;j<jn;j++){
			scanf("%s : %s", c, p);
			switch(p[0]){
			case 'g':
				if((strcmp(g[0], c)==0)||
					(strcmp(g[1], c)==0)||
					(strcmp(g[2], c)==0)||
					(strcmp(g[3], c)==0)){
					l++;
				}
				break;
			case 's':
				if((strcmp(s[0], c)==0)||
					(strcmp(s[1], c)==0)||
					(strcmp(s[2], c)==0)||
					(strcmp(s[3], c)==0)){
					l++;
				}
				break;
			case 'b':
				if((strcmp(b[0], c)==0)||
					(strcmp(b[1], c)==0)||
					(strcmp(b[2], c)==0)||
					(strcmp(b[3], c)==0)){
					l++;
				}
				break;
			default:
				while(1);
				break;
			}
		}
		if(l==max){
			count++;
		} else if(l>max){
			count=1;
			max=l;
		}
	}
	printf("%d", count*5);
	return 0;
}

