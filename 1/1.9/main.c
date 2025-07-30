#include <stdio.h>

int main() {
	int c;
	int space = 0;

	while ((c = getchar()) != '.') {
		if (c == ' ' && space);
		else if (c == ' ') {
			++space;
			putchar(' ');
		}
		else {
			space = 0;
			putchar(c);
		}
	}

	return 0;
}
