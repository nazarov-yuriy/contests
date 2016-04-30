#include <stdio.h>
#include <math.h>

int main(){
	int n, i;
	scanf("%d", &n);
	if(n<3){
		printf("%d %d", n, 1);
		return 0;
	}
	n*=2;
	for(i=sqrt(n)+1;i-->1;){
		if((n%i)==0){
			//printf("%d\n", i);
			if( (((n-i*(i+1))%(2*i))==0) && ((n-i*(i+1))>=0) ){
				printf("%d %d\n", (n-i*(i+1))/i/2+1, i);
				return 0;
			}
		}
	}
	return 0;
}

