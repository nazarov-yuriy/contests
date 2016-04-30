#include <stdio.h>

int is_new_s = 1;
char ch;

int main()
{
	while((ch=getchar())>0){
		if((ch=='.')||(ch=='?')||(ch=='!')){
			is_new_s = 1;
		}
		if((ch>='A')&&(ch<='Z')){
			if(is_new_s){
				is_new_s = 0;
			} else {
				ch -= 'A' - 'a';
			}
		}
		putchar(ch);
	}
	return 0;
}
