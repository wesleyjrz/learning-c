#include <stdio.h>

#define MAXL 20

/*
 * Wesley V. Santos Jr.
 * world length histogram - v1
 *
 * print a histogram showing the frequency of words with a given length
 *
 * NOTE: if EOF is sent, the program ignores the last word characters count;
 * only words up to 20 characters length are supported.
 */
int main()
{
	int c, i, bar, length[MAXL];
	for (i = 0; i <= MAXL; ++i)
		length[i] = 0; /* assign a initial value for every subscript */

	printf("Words length histogram v1\nby Wesley Jr.\n\n");
	printf("Input: ");

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n' && c != EOF) {
			++i;
		} else {
			++length[0]; /* count blank characters */
			++length[i]; /* add one to the last word length group */
			i = 0;
		}
	}

	printf("\n");
	for (i = 0; i <= MAXL; ++i) {
		if (i == 0) {
			printf("\n   blank characters |");
		} else {
			printf("\n%2d characters words |", i);
		}
		for (bar = 1; bar <= length[i]; ++bar)
			printf("-");
	}
	printf("\n");

	return 0;
}
