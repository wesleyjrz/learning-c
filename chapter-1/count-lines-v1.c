#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * count lines - v1
 */
int main()
{
	double c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%.0f\n", nl);

	return 0;
}
