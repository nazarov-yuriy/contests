#include <stdio.h>

int main() {
	int a, b, c, d, t;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a >= c)
		printf("%d", a);
	else {
		t = (c - a) / (b + d);
		a += b * t;
		c -= d * t;
		if ((a + b) > c)
			printf("%d", c);
		else
			printf("%d", a + b);
	}
	return 0;
}
