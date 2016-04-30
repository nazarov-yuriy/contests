/*
 * 1022.c
 *
 *  Created on: 23 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int arr[110];
int in[110][110];

void mv(int f, int t){
	while(t>f){
		arr[t]=arr[t-1];
		t--;
	}
}

int find(int val, int c){
	int i;
	for(i=0;i<c;i++)
		if(arr[i]==val)
			return i;
	return -1;
}
void print(int n){
	int j;
	for(j=0;j<n;j++)
		printf("%d ",arr[j]);
	printf("\n");
}

int main(){
	int n, i, j, t;

	scanf("%d", &n);
	for(i=0;i<n;i++)
		arr[i]=i+1;

	for(i=1;i<=n;i++){
		int p = 0;
		scanf("%d", &t);
		in[i-1][p++] = t;
		while(t){
			//printf("s%d: ", i);
			//print(n);
			int f=find(t,n);
			int to=find(i,n);
			//printf("%d %d\n", f, to);
			int tmp;
			if(f<to){
				tmp = arr[to];
				mv(f, to);
				arr[f] = tmp;
			}
			scanf("%d", &t);
			in[i-1][p++] = t;
			//printf("e%d: ", i);
		}
		//print(n);
	}
for(j=0;j<n;j++)
	for(i=1;i<=n;i++){
		int p = 0;
		t = in[i-1][p++];
		while(t){
			//printf("s%d: ", i);
			//print(n);
			int f=find(t,n);
			int to=find(i,n);
			//printf("%d %d\n", f, to);
			int tmp;
			if(f<to){
				tmp = arr[to];
				mv(f, to);
				arr[f] = tmp;
			}
			t = in[i-1][p++];
			//printf("e%d: ", i);
		}
		//print(n);
	}

	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}

