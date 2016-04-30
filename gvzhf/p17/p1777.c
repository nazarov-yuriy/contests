/*
 * 1777.c
 *
 *  Created on: 22 Feb 2012
 *      Author: firefish
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void add(uint64_t el, uint64_t *piles, int *c){
	piles[(*c)++] = el;
}

uint64_t min_delta(uint64_t *piles, int count){
	int i,j;
	uint64_t m_delta = (piles[1] > piles[0])?(piles[1] - piles[0]):(piles[0] - piles[1]);
	for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++){
			uint64_t d = (piles[i] > piles[j])?(piles[i] - piles[j]):(piles[j] - piles[i]);
			if(d<m_delta){
				//printf("%lld<%lld\n", d, m_delta);
				m_delta = d;
			} else {
				//printf("%lld>%lld\n", d, m_delta);
			}
		}
	}
	return m_delta;
}

void print(uint64_t *piles, int count){
	int i;
	for(i=0;i<count;i++)
		printf("%lld ", piles[i]);
	printf("\n");
}

int main(){
	int c = 3, res = 1;
	uint64_t piles[500], delta;
	scanf("%lld %lld %lld", &piles[0], &piles[1], &piles[2]);
	while(delta=min_delta(piles, c)){
		//print(piles, c);
		res++;
		add(delta, piles, &c);
		//print(piles, c);
	}
	printf("%d", res);
	return 0;
}

