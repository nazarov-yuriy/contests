#include <stdio.h>

int main()
{
	int n, i, tn, to, c = 1;
	scanf("%d", &n);
	scanf("%d", &to);
	for(i = 1; i<n; i++){
		scanf("%d", &tn);
		if(tn==to){
			c++;
		} else {
			printf("%d %d ", c, to);
			to = tn;
			c = 1;
		}
	}
	printf("%d %d ", c, to);
	return 0;
}
