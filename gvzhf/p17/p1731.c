#include <stdio.h>

int n, m, i;

int main()
{
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
		printf("%d ", i+1);
	printf("\n");
	for(i=0;i<m;i++)
		printf("%d ", (i+1)*(n+1));
	return 0;
}
