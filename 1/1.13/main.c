#include <stdio.h>

#define SIZE 100


int main() {
	int c, last_c = ' ', nword = 0, count = 0;
	int nwords[SIZE];


	for (int i = 0; i < SIZE; ++i) 
		nwords[i] = 0;

	while ((c = getchar()) != '.') {
		if (c == ' ' && last_c != ' ') {
			nwords[nword++] = count;
			count = 0;
		}
		else
			++count;
		last_c = c;
	}

	for (int i = 0; nwords[i] != 0; ++i)
		printf("%d ", nwords[i]);
	printf("\n");

	return 0;
}
