#include <stdio.h>

int arr[10000];

int main()
{
	int n, m, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(i+j<n)
				scanf("%d", &arr[(1+j+i)*(2+j+i)/2-i-1]);
			else
				scanf("%d", &arr[(1+j+i)*(2+j+i)/2-i-(i+j+1-n)*(i+j+1-n)-1]);
	}
	for(i=0;i<n*n;i++)
		printf("%d ", arr[i]);
	return 0;
}
