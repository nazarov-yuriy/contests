#include <stdio.h>
#include <string.h>

unsigned int gcd(unsigned int a, unsigned int b) {  
  unsigned int t;  
  while (b != 0) {  
    t = b;  
    b = a % b;  
    a = t;  
  }  
  return a;  
}

unsigned int t[1001] = {0};
unsigned int a[1001] = {0};
unsigned int b[1001] = {0};
unsigned int d[1001] = {0};
int main(void) {
	unsigned int n,i,j;
	unsigned long int tmp;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		a[i] = i+1;
		scanf("%d", &b[i]);
	}
	for(i=0;i<n+1;i++){
		memcpy(t, a, 4004);
		for(j=0;j<n;j++){
			a[j]=t[ b[j]-1 ];
		}
		for(j=0;j<n;j++){
			if(a[j]==j+1 && d[j]==0)
				d[j] = i+1;
		}
		/*for(j=0;j<n;j++){
			printf("%d ", a[j]);
		}
		printf("\n");*/
	}

	/*printf("\n");*/
	tmp = d[0];
	for(j=1;j<n;j++){
		tmp = (tmp / gcd(tmp, d[j])) * d[j];
	}
/*	printf("\n");
	printf("\n");*/
	printf("%ld", tmp);
	return 0;
}

