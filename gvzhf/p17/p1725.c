#include <stdio.h>

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	k=(k>(n/2))?n-k+1:k;
	printf("%d", (n>2)?n-2-k:0 );
	return 0;
}

