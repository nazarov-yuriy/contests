#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	char str[256];
	scanf("%d", &n);
	gets(str);
	printf("+------------------------------+--------+-------------+\n");
	printf("|Contest name                  |Date    |ABCDEFGHIJKLM|\n");
	printf("+------------------------------+--------+-------------+\n");
	for(int i = 0; i < n; i++){
		int p, s;
		char name[256], date[256];
		char prob_state[14] = "             ";
		gets(name);
		gets(date);
		scanf("%d%d", &p, &s);
		gets(str);
		for(int j = 0; j < p; j++){
			prob_state[j] = '.';
		}
		for(int j = 0; j < s; j++){
			char c;
			c = getchar();
			getchar();
			gets(str);
			if(0 == strcmp("Accepted", str)){
				prob_state[ c - 'A' ] = 'o';
			} else if(prob_state[ c - 'A' ] != 'o') {
				prob_state[ c - 'A' ] = 'x';
			}
		}
		printf("|%-30s|%-8s|%-13s|\n", name, date, prob_state);
		printf("+------------------------------+--------+-------------+\n");
	}
	return 0;
}
