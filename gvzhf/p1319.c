#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(i<=j)
				printf("%d ", ((n-j+i)*(n-j+i-1))/2+i+1);
			else
				printf("%d ", n*(n-1)-((n-i+j)*(n-i+j-1))/2 + i + 1 );
		printf("\n");
	}
	return 0;
}
