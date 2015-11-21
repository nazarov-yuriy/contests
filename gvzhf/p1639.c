#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if( (m*n) % 2 == 0)
		printf("[:=[first]");
	else
		printf("[second]=:]");
	return 0;
}
