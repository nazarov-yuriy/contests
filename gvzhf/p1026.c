#include <stdio.h>

int n, m, i, t;
int arr[100000];
char buf[100];

void pos_sort(int _first, int _last, int pos) {
	int first;
	int last;
	//printf("\ncall:%d %d \n", _first, _last);
	/*for (i = 0; i < n; i++)
			printf("%d\n", arr[i]);*/

	if((pos==0)||(_first>=_last))
		return;

	first = _first;
	last = _last;
	do {
		while ((!(arr[first] & pos)) && (first < last))
			first++;
		while (((arr[last] & pos)) && (first < last))
			last--;
		//printf("[%d]=%d [%d]=%d\n", first, arr[first], last, arr[last]);
		t = arr[first];
		arr[first] = arr[last];
		arr[last] = t;
	} while (first < last);
	if(arr[first]&pos)
		last--;
	if(!(arr[first]&pos))
		first++;
	pos_sort(_first, last, pos >> 1);
	pos_sort(first, _last, pos >> 1);
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	pos_sort(0, n - 1, 1<<30);
	gets(buf);
	gets(buf);
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &t);
		printf("%d\n", arr[t-1]);
	}
	return 0;
}
