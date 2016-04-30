#include <stdio.h>
#include <string.h>

#define min(x, y) (((x)>(y)) ? (y) : (x))
#define max(x, y) (((x)<(y)) ? (y) : (x))

int main()
{
	char unused[24];
	char dev[6][24];
	int cost[6];
	int count[6] = {1,1,1,1,1,1};
	int maxcount = 0;
	int gmincost = 1000500;
	for(int i = 0; i < 6; i++){
		scanf("%s", unused);
		scanf("%s", dev[i]);
		scanf("%d", &cost[i]);
	}
	for(int i = 0; i < 5; i++){
		int mincost = cost[i];
		for(int j = i+1; j<6; j++){
			if(0==strcmp(dev[i],dev[j])){
				mincost = min(mincost, cost[j]);
				count[i]++;
			}
		}
		cost[i] = mincost;
	}
	for(int i = 0; i < 6; i++){
		maxcount = max(maxcount,count[i]);
	}
	for(int i = 0; i < 6; i++){
		if(maxcount == count[i]){
			gmincost = min(gmincost, cost[i]);
		}
	}
	for(int i = 0; i < 6; i++){
		if(maxcount == count[i] && cost[i] == gmincost){
			printf("%s", dev[i]);
			return 0;
		}
	}
	return 0;
}
