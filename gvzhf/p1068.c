#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	a = ((abs(a)+1)*a)/2;
	if(a<=0) a++;
	printf("%d\n", a);
	return 0;
}
