#include <stdio.h>

int main() {
	char c;

	while ((c = getchar()) != 'q')
		putchar(c);

	return 0;
}
