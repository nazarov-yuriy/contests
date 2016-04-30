#include <stdio.h>

int main()
{
	int k, n, t, res = 0;
	scanf("%d %d", &k, &n);
	for(;n>0;n--){
		scanf("%d", &t);
		res += t - k;
		if (res < 0)
			res = 0;
	}
	printf("%d", res);
	return 0;
}
