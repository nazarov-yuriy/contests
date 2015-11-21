#include <stdio.h>

char ch;
char stack[200500];
int stackpos = 0;

void push(char c){
	stackpos++;
	stack[stackpos] = c;
}

int main(){
	while((ch=getchar())>0){
		if(stack[stackpos]==ch)
			stackpos--;
		else
			push(ch);
	}
	push(0);
	printf("%s", &stack[1]);
	return 0;
}
