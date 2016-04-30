#include <stdio.h>

int main()
{
	long n, st = 0, res = 1;
	char c;
	scanf("%ld", &n);
	scanf("%c", &c);//' '
	scanf("%c", &c);//'!'
	while(c=='!'){
		st++;
		scanf("%c", &c);
	}
	for(;n>0;n-=st){
		res *= n;
	}
	printf("%ld\n", res);
	return 0;
}
