#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * blank fixer - v1
 *
 * output a string replacing every sequence of blanks by a single blank
 */
int main()
{
	for (int c; (c = getchar()) != EOF; putchar(c))
		if (c == ' ') {
			putchar(' ');
			/* ignore any blanks after a blank */
			while ((c = getchar()) == ' ')
				;
		}

	return 0;
}
