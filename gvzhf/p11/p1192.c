#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main(){
	int v, a;
	double k;
	scanf("%d%d%lf", &v, &a, &k);
	printf("%.2f", (1.0/(1.0-1.0/k))*2.0*v*v*sin(a*PI/180)*cos(a*PI/180)/10.0+0.00000001 );
	return 0;
}

