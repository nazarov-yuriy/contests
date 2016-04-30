#include <stdio.h>

int main()
{
	int n, i, res = 0;
	char pay[256];
	char c;
	for(i=0; i<256; i++)
		pay[i]=0;
	for(i=0; i<9; i++){
		pay['a'+i*3] = 1;
		pay['b'+i*3] = 2;
		pay['c'+i*3] = 3;
	}
	pay['.'] = 1;
	pay[','] = 2;
	pay['!'] = 3;
	pay[' '] = 1;
	while ((c = getchar()) != EOF)
	{
		res += pay[c];
	}

	printf("%d", res);
	return 0;
}
