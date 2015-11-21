#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", (m-n+1)/2+(m%2+n%2)/2);
	return 0;
}
