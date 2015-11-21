#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	n = (2*n+(k-1))/k;
	if(n==1)
		n = 2;
	printf("%d", n);
	return 0;
}
