#include <stdio.h>
#define min(a, b) ((a<b)?(a):(b))

int arr[4][4];
int i, j, t;

int main()
{
	for(i=0;i<4;i++)
		for(j=0;j<4;j++){
			scanf("%d", &t);
			arr[i][j] = t - 1;
			if(t==4)
				arr[i][j] = 1;
		}
	printf("%d", min(min(arr[0][0]+arr[0][1]+arr[1][0]+arr[1][1],
			arr[0][2]+arr[0][3]+arr[1][2]+arr[1][3]),min(
			arr[2][0]+arr[2][1]+arr[3][0]+arr[3][1],
			arr[2][2]+arr[2][3]+arr[3][2]+arr[3][3])));
	return 0;
}
