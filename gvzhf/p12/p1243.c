#include <stdio.h>

char c;
long long int summ = 0;

int main()
{
	while((c=getchar())>0){
		if((c<'0')||(c>'9'))
			continue;
		summ*=10;
		summ+=c-'0';
		if(summ>1000000000000000)
			summ=summ%7;
	}
	summ=summ%7;
	printf("%lld", summ);
	return 0;
}
