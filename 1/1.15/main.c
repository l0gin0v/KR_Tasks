#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double fahr2celc(int fahr) {
	return (5.0 / 9.0) * (fahr-32);
}

int main() {
	printf("Фаренгейт Цельсий\n");
	for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%9d %7.1f\n", fahr, fahr2celc(fahr));

	return 0;
}

