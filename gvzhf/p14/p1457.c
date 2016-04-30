#include <stdio.h>

int main()
{
	int n, i, t;
	long long r = 0;
	long double res = 0.0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t);
		r += t;
	}
	res = 1.0L*r/n;
	printf("%0.6Lf", res);
	return 0;
}
