#include <stdio.h>

int n, m, i, max = 2, min = 10;
char c[100];

int main()
{
	scanf("%d", &n);
	gets(c);
	for(i = 0; i < n; i++){
		gets(c);
		if(c[2] == 'h'){
			if((c[0]-'0')>max)
				max = c[0]-'0';
		} else {
			if((c[0]-'0')<min)
				min = c[0]-'0';
		}
	}
	if(max>=min)
		printf("Inconsistent");
	else
		printf("%d", min);
	return 0;
}
