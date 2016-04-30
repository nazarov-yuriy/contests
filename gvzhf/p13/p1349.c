#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	switch(n){
	case 1:
		printf("1 2 3\n");
		break;
	case 2:
		printf("3 4 5\n");
		break;
	default:
		printf("-1\n");
		break;
	}
	return 0;
}
