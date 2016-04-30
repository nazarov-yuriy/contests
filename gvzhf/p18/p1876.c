#include <stdio.h>

int n, m;
#define max(a, b) ((a)>(b))?(a):(b)

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d", max(120+2*(m-40),119+2*(n-40)));
	return 0;
}
