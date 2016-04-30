#include <stdio.h>

char arr[2100];

int main()
{
	int n, m, i;
	char c;
	scanf("%d", &n);
	gets(arr);
	for(i=0;i<n;i++)
		gets(arr+2*i);
	scanf("%c", &c);
	for(i=0;i<n;i++)
		if(arr[2*i]==c)
			printf("%c%c\n", arr[2*i], arr[2*i+1]);
	return 0;
}
