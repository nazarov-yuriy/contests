#include <stdio.h>
int main()
{
	int n, i, c = 0;
	scanf("%d", &n);
	for(i = 1; i<n; i*=2){
		c++;
	}
	printf("%d", c);
	if(c>0){
		printf("\n");
		for(n-=n/2;n>1;n-=n/2)
			printf("%d ", n);
		printf("1");
	}
	printf("\n");
	return 0;
}
