#include <stdio.h>

int main(){
	int n, c, mc=2;
	unsigned int summ = 0, max = 0, t1,t2,t3;
	scanf("%d", &n);
	scanf("%d", &t1); summ += t1;
	scanf("%d", &t2); summ += t2;
	scanf("%d", &t3); summ += t3;
	max=summ;
	for(c=3;c<n;c++){
		summ -= t1;
		t1=t2;
		t2=t3;
		scanf("%d", &t3);
		summ+=t3;
		if (summ>max){
			max=summ;
			mc=c;
		}
	}
	printf("%d %d", max, mc);
	return 0;
}

