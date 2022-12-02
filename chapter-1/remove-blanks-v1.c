/*
 */

#include <stdio.h>

#define STR_LIM 1000

int getsline(char line[], int start, int limit);
int rmchar(char string[], int position);
int getline_pos(char string[], int line);
int rmtrail(char string[], int line);
void rmvoid(char string[]);

/*
 * Wesley V. Santos Jr.
 * remove blanks - v1
 *
 * remove trailing blanks and tabs and delete blank lines
 *
 * NOTE: I know I didn't need to create the getline_pos() function to get the
 * lines position, since getsline() returns string length. However I wanted to
 * create it just for fun.
 */
int main()
{
	int len, lin;
	char string[STR_LIM];

	len = lin = 0;
	while ((len = getsline(string, len, STR_LIM)) > 0)
		if (string[len-1] == '\n') {
			++lin;
			len = rmtrail(string, lin);
			++len;
		}

	rmtrail(string, lin+1);
	rmvoid(string);

	if (lin > 0)
		printf("%s\n", string);

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
 * rmchar: remove a character from a string, return length
 */
int rmchar(char s[], int p)
{
	/* take next characters and put them in the previous subscript */
	while (s[p] != '\0') {
		s[p] = s[p+1];
		++p;
	}

	return p-1;
}

/*
 * getline_pos: return start position for a given line, if the line does not
 * exist return 0.
 */
int getline_pos(char s[], int lin)
{
	int p = 0;

	if (lin == 1)
		return 0;

	while (lin > 1) {
		while (s[i] != '\n' && s[i] != '\0')
			++i;
		if (s[i] == '\0') /* find end of the string before finish */
			return 0;
		++p;
		--lin;
	}

	return p;
}

/*
 * rmtrail: remove trailing blanks and tabs in a line, return string length
 */
int rmtrail(char s[], int lin)
{
	int i;
	lin = getline_pos(s, lin);

	/* go to the end of a line */
	for (i = lin; s[i] != '\n' && s[i] != '\0'; ++i)
		;

	/* remove previous whitespaces */
	while (s[i-1] == ' ' || s[i-1] == '\t') {
		rmchar(s, i-1);
		--i;
	}

	return i;
}

/*
 * rmvoid: remove empty lines
 */
void rmvoid(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		while (s[i] == '\n' && s[i+1] == '\n')
			rmchar(s, i+1);
}
