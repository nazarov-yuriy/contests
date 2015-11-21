#include <stdio.h>
#include <stdint.h>

long long summ[65535]={0};

int main(){
	long long min=1e+10,max_delta=0;
	int i,n,j;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%lld", &summ[i]);
	}
	for(i=1;i<=n;i++){
		summ[i]+=summ[i-1];
	}
	for(i=0;i<=n;i++){
		if(min>summ[i]){
			min=summ[i];
		}
		if(summ[i]-min>max_delta){
			max_delta = summ[i]-min;
		}
	}
	printf("%lld", max_delta);
	return 0;
}

