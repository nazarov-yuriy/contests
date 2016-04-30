/*
 * 1711.c
 *
 *  Created on: 23 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>
#include <string.h>

typedef char* ref;

char c[3][20][25];
ref  c_a[3][20];
int p[20];

int main() {
	int n, i;
	char res[1000];
	char tmp[30];
	char *last;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s %s", c[0][i], c[1][i], c[2][i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (i = 0; i < n; i++) {
		if ((strcmp(c[0][p[i] - 1], c[1][p[i] - 1]) < 0)
				&& (strcmp(c[0][p[i] - 1], c[2][p[i] - 1]) < 0)){
			c_a[0][i] = c[0][p[i] - 1];
			if(strcmp(c[1][p[i] - 1], c[2][p[i] - 1]) < 0){
				c_a[1][i] = c[1][p[i] - 1];
				c_a[2][i] = c[2][p[i] - 1];
			} else {
				c_a[1][i] = c[2][p[i] - 1];
				c_a[2][i] = c[1][p[i] - 1];
			}
		}

		if ((strcmp(c[1][p[i] - 1], c[0][p[i] - 1]) < 0)
				&& (strcmp(c[1][p[i] - 1], c[2][p[i] - 1]) < 0)){
			c_a[0][i] = c[1][p[i] - 1];
			if(strcmp(c[0][p[i] - 1], c[2][p[i] - 1]) < 0){
				c_a[1][i] = c[0][p[i] - 1];
				c_a[2][i] = c[2][p[i] - 1];
			} else {
				c_a[1][i] = c[2][p[i] - 1];
				c_a[2][i] = c[0][p[i] - 1];
			}
		}

		if ((strcmp(c[2][p[i] - 1], c[1][p[i] - 1]) < 0)
				&& (strcmp(c[2][p[i] - 1], c[0][p[i] - 1]) < 0)){
			c_a[0][i] = c[2][p[i] - 1];
			if(strcmp(c[0][p[i] - 1], c[1][p[i] - 1]) < 0){
				c_a[1][i] = c[0][p[i] - 1];
				c_a[2][i] = c[1][p[i] - 1];
			} else {
				c_a[1][i] = c[1][p[i] - 1];
				c_a[2][i] = c[0][p[i] - 1];
			}
		}
	}

	sprintf(res, "%s\n", c_a[0][0]);
	last = c_a[0][0];
	for (i = 1; i < n; i++) {
		if(strcmp(last, c_a[0][i])<0){
			sprintf(tmp, "%s\n", c_a[0][i]);
			last = c_a[0][i];
		} else if(strcmp(last, c_a[1][i])<0){
			sprintf(tmp, "%s\n", c_a[1][i]);
			last = c_a[1][i];
		} else if(strcmp(last, c_a[2][i])<0){
			sprintf(tmp, "%s\n", c_a[2][i]);
			last = c_a[2][i];
		} else  {
			printf("IMPOSSIBLE");
			return 0;
		}
		strcat(res, tmp);
	}
	printf("%s", res);
	return 0;
}

