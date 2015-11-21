#include <stdio.h>

int n, m, i, c[10], t;

int main()
{
	scanf("%d %d", &n, &m);
	m = m % n;
	for(i=0;i<n;i++){
		scanf("%d", &t);
		if(i<10)
			c[i] = t;
		if((i>=m)&&(i<10+m))
			printf("%d", t);
	}
	for(i=0; i<(10+m-n);i++)
		printf("%d", c[i]);
	return 0;
}
