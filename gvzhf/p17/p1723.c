#include <stdio.h>

int max = 0, pos, i;
char count[26], c;

int main()
{
	for(i = 0; i < 26; i++)
		count[i]=0;
	while(scanf("%c", &c)>0){
		c -= 'a';
		if((c>=0)&&(c<=25)){
			count[c]++;
		}
	}
	for(i = 0; i < 26; i++)
		if(count[i]>max){
			max = count[i];
			pos = i;
		}
	printf("%c", pos+'a');

	return 0;
}
