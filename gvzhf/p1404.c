#include <stdio.h>

char c[101];
int n, l = 0, i;

int main()
{
	while(scanf("%c", &c[l])>0){
		if( (c[l]>='a')&&(c[l]<='z') )
			l++;
	}
	c[l] = 0;
	for(i = 0; i < l; i++)
		c[i]-='a'+5;
	for(i = 0; i < l; i++)
		if(c[i] < 0)
			c[i] += 26;
	for(i = l-1; i > 0; i--){
		c[i] -= c[i-1];
		if(c[i] < 0)
			c[i] += 26;
	}
	for(i = 0; i < l; i++)
		c[i]+='a';
	printf("%s", c);
	return 0;
}
