/*
 * 1837.c
 *
 *  Created on: 21 Feb 2012
 *      Author: firefish
 */
#include <string.h>
#include <stdio.h>

int Isenb = -1;

int add(char name[21], char names[301][21], int *count){
	int pos = -1, i;
	for(i=0;i<*count;i++){
		if (strcmp(name, names[i]) == 0)
			return i;
	}
	strcpy(names[*count], name);
	return (*count)++;
}

void sort(char names[301][21], int cf[301], int count){
	int i, j, t;
	char c[20];
	for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++){
			if(strcmp(names[i], names[j]) > 0){
				strcpy(c, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], c);
				t=cf[i];
				cf[i]=cf[j];
				cf[j]=t;
			}
		}
	}
}

int main(){
	int n, i, j;
	char names[301][21];
	int cf[301];
	int cmds[101][3];
	char name[21];
	int count = 0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", name);
		cmds[i][0] = add(name, names, &count);
		scanf("%s", name);
		cmds[i][1] = add(name, names, &count);
		scanf("%s", name);
		cmds[i][2] = add(name, names, &count);
	}
	for(i=0;i<count;i++){
		cf[i] = -1;
		if(strcmp(names[i], "Isenbaev")==0)
			Isenb = i;
	}
	if(Isenb < 0){
	} else {
		cf[Isenb] = 0;
		for(j=0;j<n*5;j++){
			for(i=0;i<n;i++){
				if( cf[cmds[i][0]] == j){
					if(cf[cmds[i][1]]<0) cf[cmds[i][1]] = j+1;
					if(cf[cmds[i][2]]<0) cf[cmds[i][2]] = j+1;
				}
				if( cf[cmds[i][1]] == j){
					if(cf[cmds[i][2]]<0) cf[cmds[i][2]] = j+1;
					if(cf[cmds[i][0]]<0) cf[cmds[i][0]] = j+1;
				}
				if( cf[cmds[i][2]] == j){
					if(cf[cmds[i][0]]<0) cf[cmds[i][0]] = j+1;
					if(cf[cmds[i][1]]<0) cf[cmds[i][1]] = j+1;
				}
			}
		}
	}
	sort(names, cf, count);
	for(i=0;i<count;i++){
		if(cf[i]>=0)
			printf("%s %d\n", names[i], cf[i]);
		else
			printf("%s undefined\n", names[i]);
	}

	return 0;
}
