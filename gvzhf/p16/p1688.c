#include <stdio.h>

int main()
{
	long long int n, m, i, t, summ = 0;
	scanf("%lld %lld", &m, &n);
	for(i = 0; i < n; i++){
		scanf("%lld", &t);
		summ += t;
		if(summ>3ull*m){
			printf("Free after %lld times.", i+1);
			return 0;
		}
	}
	printf("Team.GOV!");
	return 0;
}
