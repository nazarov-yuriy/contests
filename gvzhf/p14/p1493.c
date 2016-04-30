#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d", &n);
	n++;
	if( (n%10+(n/10)%10+(n/100)%10) == ((n/1000)%10+(n/10000)%10+(n/100000)%10) ){
		printf("Yes");
	} else {
		n-=2;
		if( (n%10+(n/10)%10+(n/100)%10) == ((n/1000)%10+(n/10000)%10+(n/100000)%10) ){
			printf("Yes");
		} else {
			printf("No");
		}
	}
	return 0;
}
