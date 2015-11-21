#include <stdio.h>
#include <stdint.h>

char str[2002];

int8_t comp(int n){
	int i;
	for(i=n/2-1; i>=0; i--){
		if(str[n-1-i]>str[i])
			return 1;
		if(str[n-1-i]<str[i])
			return 0;
	}
	return 0;
}

void inc(int len){
	char carry = 0;
	len--;
	str[len]+=1+carry;
	carry=str[len]/10;
	str[len]=str[len]%10;


	for(;len-->0;){
		str[len]+=carry;
		carry=str[len]/10;
		str[len]=str[len]%10;
	}
}

int main(){
	int i,n=0,c;
	while(EOF/*'\n'*/!=(c=getchar())){
		if('0'<=c&&c<='9'){
			str[n++]=c-'0';
		}
	}
	if(comp(n))
		inc((n-1)/2+1);
	/*for(i=0;i<n;i++)
		putchar(str[i]+'0');*/

	for(i=0;i<=(n-1)/2;i++)
		putchar(str[i]+'0');
	//putchar(' ');
	for(i=0;i<(n)/2;i++)
		putchar(str[(n)/2-i-1]+'0');
	return 0;
}

