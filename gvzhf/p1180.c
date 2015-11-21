#include <stdio.h>

char d[256] = {};

int main(){
	int i,n=0,j;
	int c;
	while(EOF != (c = getchar())){
		c-='0';
		if(0<=c && c<=9){
			d[n++]=c;
		}
	}
//	for(j=0;j<255;j++){
		for(i=0;i<n;i++){
			d[i+1]+=10*(d[i]%3);
			d[i]/=3;
		}
		/*if(d[n])
			printf("1");
		else
			printf("0");
		d[n]=0;*/
		if(d[n])
			printf("1\n%d", d[n]/10);
		else
			printf("2");
//	}
	return 0;
}

