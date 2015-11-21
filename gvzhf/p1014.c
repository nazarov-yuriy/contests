#include <stdio.h>

long long int n;
int pos = 0;
char c[50];

int main()
{
	scanf("%lld", &n);
	if(n==1){
		printf("1");
		return 0;
	}
	if(n==0){
		printf("10");
		return 0;
	}
	while(n>1){
		if((n % 9)==0) { n /= 9; c[pos] = '9'; pos++; continue;}
		if((n % 8)==0) { n /= 8; c[pos] = '8'; pos++; continue;}
		if((n % 7)==0) { n /= 7; c[pos] = '7'; pos++; continue;}
		if((n % 6)==0) { n /= 6; c[pos] = '6'; pos++; continue;}
		if((n % 5)==0) { n /= 5; c[pos] = '5'; pos++; continue;}
		if((n % 4)==0) { n /= 4; c[pos] = '4'; pos++; continue;}
		if((n % 3)==0) { n /= 3; c[pos] = '3'; pos++; continue;}
		if((n % 2)==0) { n /= 2; c[pos] = '2'; pos++; continue;}
		printf("-1");
		return 0;
	}
	for(;pos>0;)
		printf("%c",c[--pos]);
	return 0;
}
