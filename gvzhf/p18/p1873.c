/*
 * 1873.c
 *
 *  Created on: 25.02.2012
 *      Author: firefish
 */
#include <stdio.h>

/*
 * Миша — 0,
 * Вадик — 1,
 * Лёша Е. — 2,
 * Саша — 3,
 * Ваня Б. — 4,
 * Никита — 5,
 * Федя — 6,
 * Ваня К. — 7,
 * Ден — 8,
 * Егор — 9,
 * Сяохун — 10,
 * Виталий — 11
 * Тимоте - 12,
 * Александр - 13
 */


int main(){
	int n;
	int r[14] = {
			5,
			21,
			12,
			2,
			1,
			4,
			6,
			1,
			4,
			4,
			1,
			0,
			1,
			1
	};
	scanf("%d", &n);
	printf("%d", r[n]);
	return 0;
}

