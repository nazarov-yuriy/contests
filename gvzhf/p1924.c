#include <stdio.h>

int main(){
	int n;
	scanf("%i", &n);
	if( ((n-1)/2)%2 ){
		printf( "black" );
	}else{
		printf( "grimy" );
	}
	return 0;
}

