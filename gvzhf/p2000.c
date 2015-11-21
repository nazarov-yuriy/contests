#include <stdio.h>

#define min(x, y) (((x)>(y)) ? (y) : (x))
#define max(x, y) (((x)>(y)) ? (x) : (y))

int main()
{
	int n, t, f, s, sum = 0;
	int arr[100009] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		sum += t;
		arr[i+1] = sum;
	}
	scanf("%d%d", &f, &s);
	if(f<s){
		printf("%d %d", arr[(f+s)/2], arr[n]-arr[(f+s)/2]);
	}else if(f==s){
		int max = max(arr[f], arr[n]-arr[f-1]);
		printf("%d %d", max, arr[n]-max);
	}else{
		printf("%d %d", arr[n]-arr[(f+s-1)/2], arr[(f+s-1)/2]);
	}
	return 0;
}

