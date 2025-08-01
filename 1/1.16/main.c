#include <stdio.h>

#define MAXLINE 10

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

int main() {
	int len, max;
	int fullLen;
	char line[MAXLINE];
	char pieceLine[MAXLINE];
	char longest[MAXLINE];
	
	max = fullLen = 0;
	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (fullLen == 0)
			my_copy(pieceLine, line);

		fullLen += len;

		if (line[len-1] == '\n') {
			if (fullLen > max) {
				max = fullLen;
				my_copy(longest, pieceLine);
			}
			fullLen = 0;
		}
	}
	if (max > 0)
		printf("%s\n", longest);
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

void my_copy(char to[], char from[]) {
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}
