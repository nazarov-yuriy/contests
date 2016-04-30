/*
 * 1100.c
 *
 *  Created on: 27 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int a[150000], m[150000];

void sort(int f, int t, int factor) {
	int fm = f, tm = t;
	if ((factor < 0)||(!(f<t)))
		return;
	do{
		while ((m[fm] & (1 << factor)) && (fm < tm))
			fm++;
		while ((!(m[tm] & (1 << factor))) && (fm < tm))
			tm--;
		if(fm<tm){
			int tmp = a[fm];
			a[fm] = a[tm];
			a[tm] = tmp;
			tmp = m[fm];
			m[fm] = m[tm];
			m[tm] = tmp;
		}
	}
	while(fm<tm);
	sort(f, fm-1, factor - 1);
	sort(tm, t, factor - 1);
}

int main() {
	int j, i, n, f, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &m[i]);
	}
	for(i=100;i>=0;i--)
		for(j=0;j<n;j++)
			if(m[j]==i)
				printf("%d %d\n", a[j], i);
	return 0;
}

