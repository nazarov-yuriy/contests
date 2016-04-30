#include <stdio.h>
#include <stdint.h>

#define max(x,y) ((x<y)?(y):(x))
uint16_t matrix[1001][1001] = { };
uint8_t diag[1001][1001] = { };

int main() {
	int n, m, k, i, j, x, y;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		diag[x][y] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if(diag[i][j])
				matrix[i][j] = matrix[i - 1][j-1] + 1;
			else
				matrix[i][j] = max(matrix[i - 1][j],matrix[i][j-1]);
		}
	}

	/*for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", (int)(100*(n+m-matrix[n][m]*0.58578643762690485)+0.5000000001));
	return 0;
}

