#include <stdio.h>

int n,i;
char f[1005];
char c[1005][205];
char useless[205];

int main()
{
	scanf("%d", &n);
	gets(useless);
	for(i = 0; i < n; i++){
		gets(c[i]);
		gets(useless);
		f[i] = useless[0];
	}
	printf("Slytherin:");
	for(i = 0; i < n; i++){
		if(f[i]=='S')
			printf("\n%s", c[i]);
	}
	printf("\n\nHufflepuff:");
	for(i = 0; i < n; i++){
		if(f[i]=='H')
			printf("\n%s", c[i]);
	}
	printf("\n\nGryffindor:");
	for(i = 0; i < n; i++){
		if(f[i]=='G')
			printf("\n%s", c[i]);
	}
	printf("\n\nRavenclaw:");
	for(i = 0; i < n; i++){
		if(f[i]=='R')
			printf("\n%s", c[i]);
	}
	return 0;
}
