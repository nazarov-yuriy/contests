#include <stdio.h>

int main(){
	int n, i;
	double t, s, si;
	scanf("%d %lf %lf", &n, &t, &s);
	for(i=0; i<n;i++){
		scanf("%lf", &si);
		printf("%lf\n", (t+s+si)/2);
	}
	return 0;
}

