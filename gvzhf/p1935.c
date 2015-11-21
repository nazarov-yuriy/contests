#include <stdio.h>

int main(){
	int i, n, t, m=0, s=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &t);
		if(t>m)
			m=t;
		s+=t;
	}
	s+=m;
	printf("%d", s);
	return 0;
}

