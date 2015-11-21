#include <stdio.h>
#include <math.h>
#define M_PI		3.14159265358979323846	/* pi */

int main()
{
	int a, l;
	double res, h, alph;
	scanf("%d %d", &a, &l);
	if (2.0*l*l > 1.0*a*a) {
		printf("%0.3f\n", 1.0*a*a);
	} else if (2*l <= a) {
		printf("%0.3f\n", M_PI*l*l);
	} else {
		alph = acos(a/(2.0*l));
		h = sqrt(l*l - a*a/4.0);
		printf("%0.3f\n", 8*( (M_PI/8.0 - alph/2.0)*l*l + h * a / 4.0));
	}
	return 0;
}
