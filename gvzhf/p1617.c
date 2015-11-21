#include <stdio.h>

int main()
{
	int n, i, t, res = 0;
	int count[101];
	for(i=0;i<101;i++)
		count[i]=0;
	scanf("%d", &n);
	for(;n-->0;){
		scanf("%d", &t);
		count[t-600]++;
	}
	for(i=0;i<101;i++)
		res += (count[i]/4);
	printf("%d", res);
	return 0;
}

