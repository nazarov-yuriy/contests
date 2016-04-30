#include <stdio.h>

int count[10001];
int n, m, i, t;

int main()
{
	for(i=0;i<10001;i++)
		count[i]=0;
	scanf("%d %d", &n, &m);
	for(i=0;i<m;i++){
		scanf("%d", &t);
		count[t]++;
	}
	for(i=1;i<=n;i++)
		printf("%0.2f%c\n", 100.0*count[i]/m, '%');
	return 0;
}
