#include <stdio.h>

int main(){
	long int x, y;
	scanf("%ld %ld", &x, &y);
	if(x<0 || y<0){
		printf("%ld %ld", x, y);
	}else{
		if((x+y)%2)
			printf("%ld %ld", y, x);
		else
			printf("%ld %ld", x, y);
	}
	return 0;
}

