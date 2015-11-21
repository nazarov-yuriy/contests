#include <stdio.h>

int ahash[1024*1024];

int hash(int val){
	return val;
}

void hash_add(int year){
	int key = hash(year)&0xffFff;
	while(ahash[key] && ahash[key] != year){
		key = (key+1)&0xffFff;
	}
	if(ahash[key] != year){
		ahash[key] = year;
	}
}

int hash_contains(int year){
	int key = hash(year)&0xffFff;
	while(ahash[key] && ahash[key] != year){
		key = (key+1)&0xffFff;
	}
	return ahash[key] == year;
}

int main()
{
	int n, m, t, c = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		hash_add(t);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &t);
		c += hash_contains(t);
	}
	printf("%d", c);
	return 0;
}

