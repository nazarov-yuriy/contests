#include <stdio.h>

int h, w, n, hp = 0, wp = 0, np = 0, l;
char c[101];

int main()
{
	scanf("%d %d %d", &h, &w, &n);
	gets(c);
	for(;n>0;n--){
		gets(c);
		l = strlen(c);
		if (wp + l <= w)
			wp += l + 1;
		else {
			wp = l + 1;
			if(hp<h-1)
				hp++;
			else {
				hp = 0;
				np++;
			}
		}
	}
	printf("%d", np+1);
	return 0;
}
