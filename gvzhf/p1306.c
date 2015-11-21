#include <stdio.h>

unsigned int arr[200000];

#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (X) : (Y))
/*
void print_array(int f, int t){
	for(int i = f; i <= t; i++){
		printf("%u ", arr[i]);
	}
	printf("\n");
}*/

void sort(unsigned int mask, int f, int t){
	int lf = f, lt = t;
//	printf("mask=%u from=%u to=%u\n", mask, f, t);
//	print_array(f, t);
	do{
		while(((arr[lf]&mask) == 0) && (lf <= t)){
			lf++;
		}
		while(((arr[lt]&mask) != 0) && (f <= lt)){
			lt--;
		}
		if(lf < lt){
			unsigned int tmp = arr[lf];
			arr[lf] = arr[lt];
			arr[lt] = tmp;
		}
	}while(lt>lf);
//	print_array(f, t);

//	printf("lt=%d lf=%d\n\n", lt, lf);
	if(mask > 1){
		if(f < lt)
			sort(mask >> 1, f, lt);
		if(lf < t)
			sort(mask >> 1, lf, t);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < min(n, 200000); i++){
		scanf("%u", &arr[i]);
	}
	sort(1L<<31, 0, min(n, 200000)-1);
	for(int i = 0; i < n-200000; i++){
		scanf("%u", &arr[i]);
	}
	sort(1L<<31, 0, min(n, 200000)-1);

//	print_array(0, n-1);
	if(n%2){
		printf("%u", arr[(n-1)/2 - (n-min(n, 200000))]);
	}else{
		printf("%.1f", (0.0+arr[n/2-1 - (n-min(n, 200000))]+arr[n/2 - (n-min(n, 200000))])/2.0 );
	}
	return 0;
}

