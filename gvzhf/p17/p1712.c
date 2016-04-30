#include <stdio.h>

int main()
{
	int i, j;
	char arr1[17], arr2[17], data[17];
	scanf("%s", &arr1[0]);
	scanf("%s", &arr1[4]);
	scanf("%s", &arr1[8]);
	scanf("%s", &arr1[12]);

	scanf("%s", &data[0]);
	scanf("%s", &data[4]);
	scanf("%s", &data[8]);
	scanf("%s", &data[12]);

	//print
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(arr1[i*4+j]=='X')
				printf("%c", data[i*4+j]);
	//rotate
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arr2[i*4+j] = arr1[(3-j)*4+i];
	//print
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(arr2[i*4+j]=='X')
				printf("%c", data[i*4+j]);
	//rotate
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arr1[i*4+j] = arr2[(3-j)*4+i];
	//print
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(arr1[i*4+j]=='X')
				printf("%c", data[i*4+j]);
	//rotate
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arr2[i*4+j] = arr1[(3-j)*4+i];
	//print
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(arr2[i*4+j]=='X')
				printf("%c", data[i*4+j]);
	return 0;
}
