#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * count blanks, tabs and newlines - v1
 */
int main()
{
	/* nl = newline, bk = blank, tb = tab */
	double c, nl, bk, tb;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		} else if (c == ' ') {
			++bk;
		} else if (c == '\t') {
			++tb;
		}
	}

	printf("new lines: %.0f\nblanks: %.0f\ntabs: %.0f\n", nl, bk, tb);

	return 0;
}
