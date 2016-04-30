#include <stdio.h>

int main()
{
	int n, i;
	char c[30];
	char count[65536];
	int hash;
	for(i=0;i<65536;i++)
		count[i] = 0;
	scanf("%d", &n);
	for(;n>0;n--){
		hash = 0;
		i = 0;
		scanf("%s", c);
		while(c[i]){
			hash ^=c[i]<<((i%2)*8);
			i++;
		}
		if( count[hash]++ == 1 )
			printf("%s\n", c);
	}

	return 0;
}
