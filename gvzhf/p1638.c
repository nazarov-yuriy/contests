#include <stdio.h>

int main()
{
	int w, wp, f, t;
	scanf("%d %d %d %d", &w, &wp, &f, &t);
	if(t>f){
		printf("%d", (t-f)*(w+2*wp)-w);
	} else {
		printf("%d", (f-t)*(w+2*wp)+w);
	}
	return 0;
}
