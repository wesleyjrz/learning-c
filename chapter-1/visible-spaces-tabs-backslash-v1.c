#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * visible spaces, tabs, backslash - v1
 *
 * show whitespaces as visible characters
 */
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			c -= '\t';
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			c -= '\b';
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			c -= '\\';
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}

	return 0;
}
