#include <stdio.h>
#include <math.h>

#define M_PIl		3.141592653589793238462643383279502884L
#define STEPS 67108864LL

int main()
{
	int l, h, w;
	scanf("%d%d%d", &l, &h, &w);
	if(l>=2*h){
		printf("butter");
		return 0;
	}
	long double hd, rd = l/200.0, hd0 = h/100.0, ad = 0, t;
	long long int i;
	for(i = STEPS*sqrt(2.0*(hd0-rd)/9.81L); i < 2*STEPS; i+=8){
		t = ((long double)i)/STEPS;
		hd = hd0 - 9.81L * t * t / 2.0;
		ad = 2.0*M_PIl*w*t/60.0;
		if(hd < fabs(rd*sin(ad))){
			break;
		}
	}
	i-=8;
	for(; i < 2*STEPS; i++){
		t = ((long double)i)/STEPS;
		hd = hd0 - 9.81L * t * t / 2.0;
		ad = 2.0*M_PIl*w*t/60.0;
		if(hd < fabs(rd*sin(ad))){
			if((15*STEPS+w*i)%(60*STEPS) < 30*STEPS){
				printf("butter");
			}else{
				printf("bread");
			}
//			printf("lp=%f, cos=%f, ad=%f, diff=%f, t=%f\n", (double)lower_point, (double)cos(ad), (double)ad, (double)(fmod(ad, 2.0*M_PIl) - M_PIl), (double)t);
//			printf("hd=%f, abs=%f\n", (double)hd, fabs(rd*cos(ad)));
			break;
		}
	}
	return 0;
}
