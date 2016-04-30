#include <stdio.h>
#include <string.h>

char mat[1010][1010];

int main(){
	int i,j,k,n,len,maxlen=0,mf=100500,mt;
	char str[1010];
	gets(str);
	n=strlen(str);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[i][j] = (str[i]==str[j])?1:0;
		}
	}
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			//putchar(mat[i][j]?'X':'.');
		}
		//printf("\n");
	}

	for(k=0;k<2*n-1;k++){
		for(i=k/2, j=k/2+(k&1); j<n&&i>=0; i--, j++){
			if(mat[i][j]==0)
				break;
		}
		len=(j-(k/2+(k&1)))*2+(k&1)-1;
		i++;
		j--;
		//printf("%d ", len);
		if((len>=maxlen && i<mf)||len>maxlen){
			mf=i;
			mt=j;
			maxlen=len;
		}
	}
	for(i=mf; i<=mt; i++){
		putchar(str[i]);
	}
	return 0;
}

