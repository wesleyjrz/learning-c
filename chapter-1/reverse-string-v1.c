/*
 */

#include <stdio.h>
#define LIM 1000 /* max supported length */

int getsline(char string[], int start, int limit);
void reverse(char string[], int start, int end);

/*
 * Wesley V. Santos Jr.
 * reverse strings - v1
 *
 * reverse a character string line by line
 *
 * NOTE: this program only reverses the lines ended with a newline character, I
 * know how to solve this problem using a `do while` loop without messing up all
 * the code, nevertheless I don't want to use features that were not presented.
 */
int main()
{
	int st;  /* last starting point */
	int len; /* store total line and string length */
	char line[LIM];

	st = len = 0;
	while ((len = getsline(line, len, LIM)) > 0)
		if (line[len] == '\0') {
			reverse(line, st, len-2); /* line[len-2] is after the newline character */
			st = len;
		}

	if (st > 0)
		printf("\nReversed line:\n%s\n", line);

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
 * reverse: reverse every character of a string from the start point to end
 */
void reverse(char s[], int st, int end)
{
	char c[2];

	/* take ending char, swap with starting char, then shrink positions */
	while (end > st) {
		c[0] = s[st];
		c[1] = s[end];
		s[end] = c[0];
		s[st] = c[1];
		++st;
		--end;
	}
}
