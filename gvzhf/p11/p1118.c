#include <stdio.h>
#include <math.h>

int main(){
	int i,j,l,cnt,I,J,m,prime;
	double min = 1e+10;
	scanf("%d%d", &I, &J);
	if(I==J){
		printf("%d",I);
		return 0;
	}
	if(I==1){
		printf("%d",I);
		return 0;
	}

	for(i=J;i>=I;i--){
		//printf("%d: ", i);
		cnt=1;
		prime=1;
		for(j=2;j<sqrt(i)+0.000001;j++){
			if(i%j==0){
				prime=0;
				cnt+=j;
				//printf("%d, ", j);
				if(j*j!=i){
					cnt+=i/j;
					//printf("%d, ", i/j);
				}
			}
		}
		if(prime){
			printf("%d", i);
			return 0;
		}
		//printf("= %d", cnt);
		if(min>((0.0+cnt)/i)){
			min=(0.0+cnt)/i;
			m=i;
		}
		//printf("\n");
	}
	printf("%d", m);
	return 0;
}

