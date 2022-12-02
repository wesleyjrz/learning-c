#include <stdio.h>
#define LIM 50

int power(int base, int power);
int parse_int(char *string);

/*
 * string to int
 * convert character number of any size to integer
 */
int main()
{
	char string[LIM];
	int cvalue;

	printf("Digite um valor: ");
	scanf("%s", string);
	cvalue = parse_int(string);

	printf("\n\nValor em string: %s\n", string);
	printf("Valor em inteiro: %d\n", cvalue);

	return 0;
}

/* power: raise base to n-th power */
int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;

	return p;
}

/* parse_int: convert string to integer */
int parse_int(char *s)
{
	const int char_range = 48;
	int i, j;
	int x; /* converted value */

	/* go to last character */
	for (i = 0; s[i] != '\0'; ++i)
		;
	--i;

	/* convert one by one */
	x = 0;
	for (j = 0; i >= 0; ++j) {
		x += (s[i] - char_range) * power(10, j);
		--i;
	}

	return x;
}
