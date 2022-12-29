#include <stdio.h>

#define MAXSIZ  1000
#define TABSTOP 4

int getsline(char string[], int start, int limit);
void addchar(char string[], int pos, char newchar);
int detab(char string[], int tabstop);

/*
 * Wesley V. Santos Jr.
 * detab - v1
 *
 * replace tabs with 'TABSTOP' whitespaces
 */
int main()
{
	int len = 0;
	char line[MAXSIZ];

	while ((len = getsline(line, len, MAXSIZ)) > 0)
		if (line[len-1] == '\n' || line[len] == '\0') /* detab line by line */
			len = detab(line, TABSTOP);

	if (len == EOF)
		printf("\n%s\n", line);

	return 0;
}

/*
 * getsline: read a line into '*s', starting in the given character position,
 * return length
 */
int getsline(char s[], int st, int lim)
{
	int c, i;

	for (i = st; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
		s[i] = '\0';
	} else if (c == EOF) {
		s[i] = '\0';
		return EOF;
	}

	return i;
}

/*
 * addchar: add a new character in a string after the given position
 */
void addchar(char s[], int p, char c)
{
	int i;

	/* go to the end of the string */
	for (i = p; s[i] != '\0'; ++i)
		;

	/* put characters one subscript ahead to give space for a new one */
	while (i > p) {
		s[i+1] = s[i];
		--i;
	}

	s[i+1] = c;
}

/*
 * detab: replace tabs in a string with `n` spaces, return string length
 */
int detab(char s[], int n)
{
	int i, j;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t') {
			s[i] = ' ';
			/* n-1 is used since one tab was already replaced */
			for (j = 0; j < n-1; ++j)
				addchar(s, i, ' ');
		}
	}

	return i;
}
