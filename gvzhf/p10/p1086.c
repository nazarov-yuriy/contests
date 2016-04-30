#include <stdio.h>

int n, m, i, pos, count = 1;
int matrix[1000000];

int main() {
	for (i = 0; i < 1000000; i++)
		matrix[i] = 0;
	for (i = 2; i < 1000; i++) {
		pos = 2*i;
		while (pos < 1000000) {
			matrix[pos] = 1;
			pos += i;
		}
	}
	for (i = 2; i < 1000000; i++) {
		if (!matrix[i]) {
			matrix[count] = i;
			count++;
		}
	}
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &m);
		printf("%d\n", matrix[m]);
	}
	return 0;
}
