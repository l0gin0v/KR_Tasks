#include <stdio.h>

int main() {
	float fahr, cel;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	cel = lower;
	printf("Цельсий Фаренгейт\n");
	while (cel <= upper) {
		fahr = cel * 9.0 / 5.0 + 32.0;
		printf("%7.0f %9.1f\n", cel, fahr);
		cel = cel + step;
	}
	return 0;
}

