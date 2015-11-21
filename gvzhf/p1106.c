#include <stdio.h>

char color[1001]={0};
char link[101][101];

int main(){
	int n,i,f,set,cnt=0;
	scanf("%d", &n);
	if(n<2){
		printf("0");
		return 0;
	}
	for(i=1;i<=n;i++){
		scanf("%d", &f);
		if(color[f]){
			color[i]=3-color[f];
		}
		if(color[i])
			set=3-color[i];
		else{
			color[i]=1;
			set=2;
		}
		if(!color[f]){
			color[f]=set;
		}
		scanf("%d", &f);
		while(f){
			if(!color[f]){
				color[f]=set;
			}
			scanf("%d", &f);
		}
	}
	for(i=1;i<=n;i++){
		if(color[i]==1)
			cnt++;
	}
	printf("%d\n", cnt);
	for(i=1;i<=n;i++){
		if(color[i]==1)
			printf("%d ", i);
	}
	return 0;
}

