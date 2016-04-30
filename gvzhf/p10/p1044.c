/*
 * 1044.c
 *
 *  Created on: 20 Feb 2012
 *      Author: firefish
 */
#include <stdio.h>

int main() {
	int a1, a2, a3, a4, a5, a6, a7, a8, count = 0, n;
	scanf("%d", &n);
	switch (n) {
	case 2:
		for (a1 = 0; a1 < 10; a1++)
			for (a2 = 0; a2 < 10; a2++)
				if (a1 == a2)
					count++;
		break;
	case 4:
		for (a1 = 0; a1 < 10; a1++)
			for (a2 = 0; a2 < 10; a2++)
				for (a3 = 0; a3 < 10; a3++)
					for (a4 = 0; a4 < 10; a4++)
						if (a1 + a2 == a3 + a4)
							count++;
		break;
	case 6:
		for (a1 = 0; a1 < 10; a1++)
			for (a2 = 0; a2 < 10; a2++)
				for (a3 = 0; a3 < 10; a3++)
					for (a4 = 0; a4 < 10; a4++)
						for (a5 = 0; a5 < 10; a5++)
							for (a6 = 0; a6 < 10; a6++)
								if (a1 + a2 + a3 == a4 + a5 + a6)
									count++;
		break;
	case 8:
		for (a1 = 0; a1 < 10; a1++)
			for (a2 = 0; a2 < 10; a2++)
				for (a3 = 0; a3 < 10; a3++)
					for (a4 = 0; a4 < 10; a4++)
						for (a5 = 0; a5 < 10; a5++)
							for (a6 = 0; a6 < 10; a6++)
								for (a7 = 0; a7 < 10; a7++)
									for (a8 = 0; a8 < 10; a8++)
										if (a1 + a2 + a3 + a4
												== a5 + a6 + a7 + a8)
											count++;
		break;
	}
	printf("%d", count);
	return 0;
}
