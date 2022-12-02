#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float to_fhr(float celsius);

/*
 * Wesley V. Santos Jr.
 * celsius-fahrenheit table - v2
 *
 * table of celsius-fahrenheit, now using a function
 */
int main()
{
	float celsius;

	printf("Celsius-Fahrenheit Table\nby Wesley Jr.\n\n");
	printf("°C\t °F\n");
	for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
		printf("%3.0f\t%6.1f\n", celsius, to_fhr(celsius));

	return 0;
}

/*
 * to_fhr: convert celsius to fahrenheit
 */
float to_fhr(float c)
{
	c = (c + 32.0) / 9.0 * 5.0;
	return c;
}
