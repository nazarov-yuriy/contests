#include <stdio.h>
#include <math.h>
int main()
{
	int a;
	float r, x0, y0, x1, y1, x, y, l = 0.0;
	scanf("%d %f", &a, &r);
	scanf("%f %f", &x0, &y0);
	x = x0;
	y = y0;
	for(a--;a>0;a--){
		scanf("%f %f", &x1, &y1);
		l += sqrt( (x-x1)*(x-x1) + (y-y1)*(y-y1) );
		x = x1;
		y = y1;
	}
	l += sqrt( (x-x0)*(x-x0) + (y-y0)*(y-y0) );
	printf("%0.2f\n", l + 3.1415926*2*r);
	return 0;
}
