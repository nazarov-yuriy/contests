#include <stdio.h>

int main(){
	unsigned int n, k, xk=31, xn=31;
	scanf("%d %d", &n, &k);
	if(n==1){
		printf("0");
		return 0;
	}
	while( !((1<<xk)&k) && xk>0 )
		xk--;
	while( !((1<<xn)&n) && xn>0 )
		xn--;
	xk=(xk<xn-1)?xk:xn-1;
	printf("%d", 1+(n-(1<<(xk+1))+k-1)/k+xk);
	return 0;
}

