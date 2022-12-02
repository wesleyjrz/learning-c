#include <stdio.h>

/*
 * Wesley V. Santos Jr.
 * count characters - v1
 */
int main()
{
	double cc;

	for (cc = 0; getchar() != EOF; ++cc)
		;
	printf("%.0f\n", cc);

	return 0;
}
