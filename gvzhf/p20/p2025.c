#include <stdio.h>
#include <math.h>

int sqr(int a){
	return a*a;
}

int main()
{
	int count, n, k;
	scanf("%d", &count);
	for(int i = 0; i < count; i ++){
		scanf("%d%d", &n, &k);
		if(0 == n%k)
			printf("%d\n", (n*n-k*sqr(n/k))/2);
		else
			printf("%d\n", (n*n - (n%k)*sqr(n/k+1) - (k-n%k)*sqr(n/k) )/2 );
	}
	return 0;
}

