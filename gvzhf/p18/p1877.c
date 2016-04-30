#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if ((n % 2 == 0) || (m % 2 == 1))
		printf("yes");
	else
		printf("no");
	return 0;
}
