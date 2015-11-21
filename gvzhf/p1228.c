#include <stdio.h>

int main(){
	long int n, i, x, y;
	scanf("%ld %ld", &n, &x);
	for(i=0;i<n;i++){
		scanf("%ld", &y);
		printf("%ld ", x/y-1);
		x=y;
	}
	return 0;
}

