#include <stdio.h>

#define MAXSIZ  1000
#define TABSTOP 4

int getsline(char string[], int start, int limit);
void addchar(char string[], int pos, char newchar);
int rmchar(char string[], int position);
int iscons(char string[], int pos, int times);
int entab(char string[], int tabstop);

/*
 * Wesley V. Santos Jr.
 * entab - v1
 *
 * replace whitespaces with 'TABSTOP' tabs
 */
int main()
{
	int len = 0;
	char line[MAXSIZ];

	while ((len = getsline(line, len, MAXSIZ)) > 0)
		if (line[len-1] == '\n' || line[len] == '\0') /* entab line by line */
			len = entab(line, TABSTOP);

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
 * rmchar: remove a character from a string, return length
 */
int rmchar(char s[], int p)
{
	while (s[p] != '\0') {
		s[p] = s[p+1];
		++p;
	}

	/* return length minus null-byte */
	return p-1;
}

/*
 * iscons: test if a character is `n` times consecutive in a string
 */
int iscons(char s[], int p, int n)
{
	int i = 0;
	char c = s[p]; /* store char */

	while (s[p] == c) {
		++p;
		++i;

		if (i >= n-1)
			return 1;
	}

	return 0;
}

/*
 * entab: replace spaces in a string with `n` tabs, return string length
 */
int entab(char s[], int n)
{
	int i, j;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ' && iscons(s, i, n)) {
			for (j = 0; j < n; ++j)
				rmchar(s, i);
			addchar(s, i-1, '\t');
		}
	}

	return i;
}
