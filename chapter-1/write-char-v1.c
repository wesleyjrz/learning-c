#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * write char - v1
 *
 * get input character by character and print it out on the screen
 */
int main()
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
	return 0;
}
