/*
 * 1502.c
 *
 *  Created on: 21.02.2012
 *      Author: firefish
 */

int main(){
	long long int n, j, i, s = 0;
	scanf("%lld", &n);
	for(i=0;i<=n;i++){
		for(j=i;j<=n;j++)
			s+=i+j;
	}
	printf("%lld", s);
}

