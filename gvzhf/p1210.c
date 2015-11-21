#include <stdio.h>

int cost[31][31] = {0};

int main(){
	int n, m, i, j, f, t, cst, r, min=2000000000;
	char dummy;
	for(i=1;i<31;i++){
		for(j=0;j<31;j++){
			cost[i][j]=2000000000;
		}
	}

	r=scanf("%d", &n);
	for(i=1;i<=n;i++){
		if(!scanf("%d", &m)){
			scanf("%c", &dummy);
			scanf("%d", &m);
		}
		for(t=1;t<=m;t++){
			while(1){
				r=scanf("%d", &f);
				if(!f)
					break;
				r=scanf("%d", &cst);

				if(cost[i-1][f]+cst<cost[i][t])
					cost[i][t]=cost[i-1][f]+cst;
			}
		}
		/*for(t=1;t<=m;t++){
			printf("%d ", cost[i][t]);
		}
		printf("\n");*/
	}

	for(t=1;t<=m;t++){
		if(min>cost[n][t]){
			min=cost[n][t];
		}
	}
	printf("%d", min);
	return 0;
}

