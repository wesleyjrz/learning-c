#include <stdio.h>

#define LIM 1000 /* max supported length */
#define MIN 80   /* minimun line length to print */

int getsline(char line[], int lim);
void append(char to[], char from[]);

/*
 * Wesley V. Santos Jr.
 * print long lines - v1
 *
 * print all lines longer than a minimun 'MIN' length
 */
int main()
{
	int len;         /* current line length */
	char lines[LIM]; /* stored lines */
	char cline[LIM]; /* current line */

	lines[0] = cline[0] = '\0';
	while ((len = getsline(cline, LIM)) > 0)
		if (len >= MIN) {
			append(lines, cline);
			len = 0;
		}

	if (lines[0] != '\0')
		printf("\nLines greater than %d characters:\n%s\n", MIN, lines);

	return 0;
}

/*
 * getsline: read a line into '*s', return length
 */
int getsline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/*
 * append: copy a string to the end of another string
 */
void append(char to[], char from[])
{
	int i, j;

	/* go to the end of the string */
	for (j = 0; to[j] != '\0'; ++j)
		;

	for (i = 0; (to[j] = from[i]) != '\0'; ++i)
		++j;
}
