#include <stdio.h>

int main()
{
	int n, i, e = 0, l = 0, m = 0;
	char t[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", t);
		switch(t[0]){
		case 'E': e++; break;
		case 'L': l++; break;
		case 'M': m++; break;
		}
		scanf("%s", t);
	}
	if((e>l)&&(e>m)) printf("Emperor Penguin");
	if((l>e)&&(l>m)) printf("Little Penguin");
	if((m>l)&&(m>e)) printf("Macaroni Penguin");
	return 0;
}
