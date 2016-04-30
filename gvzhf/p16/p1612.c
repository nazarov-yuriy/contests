/*
 * 1612.c
 *
 *  Created on: 27 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>
#include <string.h>

int main(){
	char c[10500];
	int tra=0,tro=0;
	while(scanf("%s", c)!=EOF){
		int pos=0;
		int st=0;
		while(c[pos]){
			if( (c[pos]=='.') || (c[pos]==',') || (c[pos]=='-') || (c[pos]==':') || (c[pos]=='!') || (c[pos]=='?') ){
				c[pos]=0;
				if(strcmp(c+st, "tram")      ==0) tra++;
				if(strcmp(c+st, "trolleybus")==0) tro++;
				st=pos+1;
			}
			pos++;
		}
		if(strcmp(c+st, "tram")      ==0) tra++;
		if(strcmp(c+st, "trolleybus")==0) tro++;
	}
	if(tra>tro){
		printf("Tram driver");
	} else if (tra<tro) {
		printf("Trolleybus driver");
	} else {
		printf("Bus driver");
	}
	return 0;
}

