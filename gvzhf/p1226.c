#include <stdio.h>

void print(char *str, int i){
	int j;
	for(j=i-1;j>=0;j--){
		putchar(str[j]);
	}
}

int main(){
	char word[300];
	int c,i=0;
	while(EOF!=(c=getchar())){
		if( ('a'<=c&&c<='z')||('A'<=c&&c<='Z') ){
			word[i++]=c;
		}else{
			print(word, i);
			i=0;
			putchar(c);
		}
	}
	print(word, i);
	return 0;
}

