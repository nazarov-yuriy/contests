#include <stdio.h>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int nod(int a, int b){
	if(a==b)
		return a;
	return nod(min(a,b),max(a,b)-min(a,b));
}

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	printf("%d", (n-1)+(m-1)-nod(m-1, n-1));
	return 0;
}

