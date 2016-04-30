#include <stdio.h>

int main()
{
	int n, m, t, i;
	scanf("%d %d", &n, &m);
	for(i=0;i<10;i++){
		scanf("%d", &t);
		m -= 20*t;
	}
	if(m<n)
		printf("Dirty debug :(");
	else
		printf("No chance.");
	return 0;
}
