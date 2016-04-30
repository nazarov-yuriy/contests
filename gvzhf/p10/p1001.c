#include <stdio.h>
#include <math.h>

#pragma comment(linker, "/STACK:1200000")

int main()
{
	int pos = 0;
	long long arr[128*1024];
	while(scanf("%lld",&arr[pos])>0) pos++;
	for(;--pos>=0;)
		if(arr[pos]==0)
			printf("0.0000\n");
		else
			printf("%0.4f\n", sqrt(arr[pos]));
	return 0;
}
