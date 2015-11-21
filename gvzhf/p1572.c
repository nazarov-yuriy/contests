#include <stdio.h>
#include <math.h>

double matrix[3][3] = {{1, 1.4142135623730951, 2},{0.5, 0.70710678118654757, 1},{0.4330127018922193, 0.61237243569579447, 0.8660254037844386}};

int main(){
	int i,cnt=0,n,size_kol,type_kol, size_luk, type_luk;
	scanf("%d%d", &type_kol, &size_kol);
	type_kol--;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d%d", &type_luk, &size_luk);
		type_luk--;
		if(matrix[type_luk][type_kol]*size_luk <= size_kol+0.000001)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}

