#include <stdio.h>

char c;
int row=0;

int main()
{
	row = getchar()-'0';
	c = getchar();
	if(c<='9'){
		row *= 10;
		row += c-'0';
		c = getchar();
	}
	if(row<3){
		if((c=='A')||(c=='D'))
			printf("window");
		else
			printf("aisle");

	} else if(row<21){
		if((c=='A')||(c=='F'))
			printf("window");
		else
			printf("aisle");
	} else if(row<66){
		if((c=='A')||(c=='K'))
			printf("window");
		else
			if((c=='C')||(c=='D')||(c=='G')||(c=='H'))
				printf("aisle");
			else
				printf("neither");
	} else
		printf("neither");

	return 0;
}
