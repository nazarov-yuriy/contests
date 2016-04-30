#include <stdio.h>

int main()
{
	int count, i, t, res = 0, pos = 1;
	char count_in_gr[10000];
	for(i=0;i<10000;i++)
		count_in_gr[i] = 0;
	scanf("%d", &count);
	for(i=0;i<count;i++){
		scanf("%d", &t);
		count_in_gr[(t+1)/2]++;
	}
	count = (count+1)/2;
	for(;count>0;count--){
		while(!count_in_gr[pos]) pos++;
		res += pos;
		count_in_gr[pos]--;
	}
	printf("%d", res);
	return 0;
}
