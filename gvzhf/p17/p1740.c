#include <stdio.h>

int main()
{
	int l, k, h, t;
	scanf("%d %d %d", &l, &k, &h);
	if(t=(l%k)){
		printf("%d.00000 %d.00000", ((l-t)/k)*h, ((l-t)/k + 1)*h);
	} else {
		printf("%d.00000 %d.00000", (l/k)*h, (l/k)*h);
	}
	return 0;
}
