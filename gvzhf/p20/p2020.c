#include <stdio.h>

int main()
{
	char s[1009], n[1009];
	int sp = 0, np = 0, t = 0;
	scanf("%s%s", s, n);
	while (s[sp] && n[np]) {
		t++;
		if ('L' == s[sp] && 'L' == n[np]) {
			sp++;
			np++;
		}else if('L' == s[sp]){
			np++;
		}else if('L' == n[np]){
			sp++;
		}else{
			sp++;
			np++;
		}
	}
	while(s[sp]){
		sp++;
		t++;
	}
	while(n[np]){
		np++;
		t++;
	}
	printf("%d", t);
	return 0;
}

