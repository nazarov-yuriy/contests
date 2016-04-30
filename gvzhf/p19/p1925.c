#include <stdio.h>

int main(){
	int n, k, i;
	int tb,tg,s=0;
	scanf("%d %d", &n, &k);
	s=k-2;
	for(i=0; i<n; i++){
		scanf("%d %d", &tb, &tg);
		s+=tb-2-tg;
	}
	if(s<0){
		printf("Big Bang!");
	}else{
		printf("%d", s);
	}
	return 0;
}

