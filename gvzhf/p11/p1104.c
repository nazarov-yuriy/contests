#include <stdio.h>

int main(){
	int c, s=0, r=1;
	while(EOF!=(c=getchar())){
		if('0'<=c&&c<='9')
			c-='0';
		else if('A'<=c&&c<='Z')
			c-=('A'-10);
		else
			continue;
		s+=c;
		if(c+1>r)
			r=c+1;
	}
	if(s==2){
		printf("3");
		return 0;
	}
	if(s==0 || s==1){
		printf("2");
		return 0;
	}
		for(;r<=36;r++){
			if((s%(r-1))==0){
				printf("%d", r);
				return 0;
			}
		}
	printf("No solution.");
	return 0;
}

