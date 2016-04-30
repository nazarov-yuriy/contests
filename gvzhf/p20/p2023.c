#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n, steps = 0;
	char str[1024];
	char *names[27] = {
		"Alice", "Ariel", "Aurora", "Phil",  "Peter",  "Olaf",   "Phoebus", "Ralph", "Robin",
		"Bambi", "Belle", "Bolt",   "Mulan", "Mowgli", "Mickey", "Silver",  "Simba", "Stitch",
		"Dumbo", "Genie", "Jiminy", "Kuzko", "Kida",   "Kenai",  "Tarzan",  "Tiana", "Winnie"
	};
	scanf("%d", &n);
	int prev = 0;
	for(int i = 0; i < n; i++){
		int pos = 0;
		scanf("%s", str);
		for(int j = 0; j < 27; j++){
			if(0==strcmp(names[j], str))
				pos = j/9;
		}
		steps += abs(pos - prev);
		prev = pos;
	}
	printf("%d", steps);
	return 0;
}

