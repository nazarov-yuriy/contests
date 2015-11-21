#include <stdio.h>

int n, m, i, t, max = -1000, min = 1000, f, b;

int main()
{
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		if((t<0)&&(t > max))
			max = t;
		if((t>0)&&(t < min))
			min = t;
	}
	if((m<max)||(m>min))
		printf("Impossible");
	else {
		f = (m<0)?2*min-m:m;
		b = (m>0)?-2*max+m:-m;
		printf("%d %d", f, b);
	}
	return 0;
}
