#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

/*
 * Wesley V. Santos Jr.
 * celsius-fahrenheit table - v1
 *
 * convert celsius to fahrenheit and print a table showing the converted values
 * from 0 to 300
 */
int main()
{
	float celsius;
	printf("Celsius-Fahrenheit Table\nby Wesley Jr.\n\n");
	printf("°C\t °F\n");
	for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
		printf("%3.0f\t%6.1f\n", celsius, (celsius + 32.0) / 9.0 * 5.0);
	return 0;
}
