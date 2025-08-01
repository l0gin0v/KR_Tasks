#include <stdio.h>

#define MAXLINE 1000
#define POINT 80

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (len > POINT)
			printf("%s\n", line);
	}
	return 0;
}

int my_getline(char s[], int lim) {
	int c, i;

	for (i = 0; i<lim-1 && (c=getchar()) != '.' && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
