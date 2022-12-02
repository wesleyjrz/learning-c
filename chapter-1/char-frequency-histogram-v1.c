#include <stdio.h>

#define MAXL 93 /* total amount of visible ASCII characters */

/*
 * Wesley V. Santos Jr.
 * characters frequency histogram - v1
 *
 * print a histogram showing the frequencies of different characters in a string
 */
int main()
{
	int c, i, bar, length[MAXL];
	for (i = 0; i <= MAXL; ++i)
		length[i] = 0; /* assign a initial value for every subscript */

	printf("Characters frequency histogram v1\nby Wesley Jr.\n\n");
	printf("Input: ");

	/*
	 * the first visible character is `!` which is 33 in the ASCII table, so the
	 * program needs to subtract 33 from every character to be in the right
	 * position
	 */
	while ((c = getchar()) != EOF)
		if (c >= 33 && c <= 126)
			++length[c - 33];

	printf("\n\nchar | frequency\n----------------\n");
	for (i = 0; i <= MAXL; ++i)
		if (length[i] > 0) {
			printf("  %c  | ", i + 33);
			 for (bar = 1; bar <= length[i]; ++bar)
				 printf("-");
			printf("\n");
		}

	return 0;
}
