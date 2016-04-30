#include <stdio.h>

int main()
{
	int n, k, arr[1000];
	scanf("%d %d", &n, &k);
	k = (n+k-1)/k;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	for(int j = 0; j < k; j++){
		for(int i = j; i < n; i+=k){
			printf("%4d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
