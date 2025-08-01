#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int maxline);

int main() {
	int len;
	char line[MAXLINE];

	while ((len = getLine(line, MAXLINE)) > 0)
		printf("%s\n", line);
	return 0;
}

int getLine(char s[], int lim) {
	int c, i;

	int tabs = 0, spaces = 0, newlines = 0;
	for (i = 0; i<lim-1 && (c=getchar())!='.' && c!='\n'; ++i) {
		printf("%c", c);
		if (c == ' ') {
			tabs = 0;
			++spaces;
			if (spaces == 2)
				continue;
		}
		else if (c == '\t') {
			spaces = 0;
			++tabs;
			if (tabs == 2)
				continue;
		}
		else {
			spaces = tabs = 0;
		}
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
