#include <stdio.h>

int main()
{
	int b[7];
	int e0, e1, e2;
	int arr[8] = {0, 6, 5, 0, 4, 1, 2, 3};
	scanf("%d %d %d %d %d %d %d", b, b+1, b+2, b+3, b+4, b+5, b+6);
	e0 = b[0]^b[1]^b[3]^b[6];
	e1 = b[0]^b[2]^b[3]^b[5];
	e2 = b[1]^b[2]^b[3]^b[4];
	if(e0+e1+e2>0)
		b[arr[e0+2*e1+4*e2]]^=1;
	printf("%d %d %d %d %d %d %d", b[0], b[1], b[2], b[3], b[4], b[5], b[6]);
	return 0;
}
