#include <stdio.h>

int n, i;
int arr[1000000];

struct context{
	int fi;
	int ti;
	int N;
	int fj;
	int tj;
	int max;
} context;

void calc_sums(int *summs, int M, int N) {
	int i, j;
		//horizontal summs all
		for (i = 0; i < M; i++) {
			for (j = 1; j < N; j++) {
				summs[i * N + j] += summs[i * N + j - 1];
			}
		}
		//vertical summs all
		for (i = 1; i < M; i++) {
			for (j = 0; j < N; j++) {
				summs[i * N + j] += summs[(i - 1) * N + j];
			}
		}

}

void find_0(struct context *str) {
	int maxLine = arr[str->ti * str->N];
	int minLine = 0;
	int lfj = -1, last_fj = -1;
	int last_tj = 0;
	int j;
	for (j = 0; j < str->N; j++) {
		if (arr[str->ti * str->N + j] - minLine > maxLine) {
			maxLine = arr[str->ti * str->N + j] - minLine;
			last_fj = lfj;
			last_tj = j;
		}
		if (arr[str->ti * str->N + j] < minLine) {
			minLine = arr[str->ti * str->N + j];
			lfj = j;
		}
	}
	str->fj = last_fj;
	str->tj = last_tj;
	str->max = maxLine;
}

void find_betwen(struct context *str) {
	int maxLine = arr[str->ti * str->N] - arr[str->fi * str->N];
	int minLine = 0;
	int lfj = -1, last_fj = -1;
	int last_tj = 0;
	int j;

	for (j = 0; j < str->N; j++) {
		if (arr[str->ti * str->N + j] - arr[str->fi * str->N + j] - minLine > maxLine) {
			maxLine = arr[str->ti * str->N + j] - arr[str->fi * str->N + j] - minLine;
			last_fj = lfj;
			last_tj = j;
		}
		if (arr[str->ti * str->N + j] - arr[str->fi * str->N + j] < minLine) {
			minLine = arr[str->ti * str->N + j] - arr[str->fi * str->N + j];
			lfj = j;
		}
	}
	str->fj = last_fj;
	str->tj = last_tj;
	str->max = maxLine;
}

int find3(int M, int N) {
	int fi, j, ti;
	int maxSum = arr[0];
	int mfi = 0, mfj = 0, mti = 1, mtj = 1;
	struct context tmp;


	for (ti = 0; ti < M; ti++) {
		tmp.N = N;
		tmp.ti = ti;
		find_0(&tmp);
		if (tmp.max >= maxSum) {
			maxSum = tmp.max;
			mfi = 0;
			mfj = tmp.fj + 1;
			mti = ti;
			mtj = tmp.tj;
		}
	}

	for (fi = 0; fi < M - 1; fi++)
		for (ti = fi + 1; ti < M; ti++) {
			tmp.N = N;
			tmp.fi = fi;
			tmp.ti = ti;
			find_betwen(&tmp);
			if (tmp.max > maxSum) {
				maxSum = tmp.max;
				mfi = fi + 1;
				mfj = tmp.fj + 1;
				mti = ti;
				mtj = tmp.tj;
			}
		}
	return maxSum;
}

int main()
{
	scanf("%d", &n);
	for(i=0;i<n*n;i++)
		scanf("%d", &arr[i]);
	calc_sums(arr, n, n);
	printf("%d", find3(n,n));
	return 0;
}
