#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

/*
 * Wesley V. Santos Jr.
 *
 * output one word per line - v1
 */
int main()
{
	int c, state;

	state = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			putchar('\n');
			state = IN;
		}
		putchar(c);
	}

	return 0;
}
