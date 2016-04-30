#include <stdio.h>
#include <math.h>

double arr[101];

void sort(int n){
	int i,j;
	double t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[i]){
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;	
			}
}

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%lf", &arr[i]);
	for(i=n;i>1;i--){
		sort(i);
		arr[i-2]=2*sqrt(arr[i-2]*arr[i-1]);
	}
	printf("%lf", arr[0]);
	return 0;
}

