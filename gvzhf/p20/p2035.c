#include <stdio.h>
#include <math.h>

#define min(x, y) (((x)>(y)) ? (y) : (x))
#define max(x, y) (((x)>(y)) ? (y) : (x))

int main()
{
	int x, y, c, a, b;
	scanf("%d%d%d", &x, &y, &c);
	a = min(x, c);
	b = min(y, c-a);
	printf(a+b<c ? "Impossible" : "%d %d", a, b);
	return 0;
}

