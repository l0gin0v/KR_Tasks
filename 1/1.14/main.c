#include <stdio.h>

#define SIZE 128

int main() {
	int c;
	int nsymbols[SIZE];

	for (int i = 0; i < SIZE; ++i)
		nsymbols[i] = 0;

	while ((c = getchar()) != '\n')
		++nsymbols[c];

	for (int i = 0; i < SIZE; ++i)
		printf("%c: %d times\n", i, nsymbols[i]);

	return 0;
}
