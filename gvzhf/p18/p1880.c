#include <stdio.h>

int main()
{
	int n, i, n1, n2 = 0, n3 = 0, p1 = 0, p2 = 0, t;
	int arr1[4000];
	int arr2[4000];
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &arr1[i]);
	n1 = n;

	scanf("%d", &n);
	for(;n>0;n--){
		scanf("%d", &t);
		while( (arr1[p1] < t)&&(p1<n1) ) p1++;
		if( arr1[p1] == t ){
			arr2[n2] = t;
			n2++;
		}
	}

	scanf("%d", &n);
	for(;n>0;n--){
		scanf("%d", &t);
		while( (arr2[p2] < t)&&(p2<n2) ) p2++;
		if( arr2[p2] == t ){
			n3++;
		}
	}
	printf("%d", n3);
	return 0;
}
