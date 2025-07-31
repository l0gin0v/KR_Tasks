#include <stdio.h>

int main(void) {
	int c;
	while ((c = getchar()) != '.')
		if (c == ' ')
			putchar('\n');
		else
			putchar(c);
	return 0;
}
