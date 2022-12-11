#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 1000

int fseekl(int count, FILE *stream);
char *fgetl(char *string, int count, FILE *stream);
void fprintl(int count, FILE *stream);

/*
 * syntax check ALPHA 0.1 - testing file read functions
 *
 * NOTE: I was learning how to read files and do operations within it, however
 * as you can notice, I didn't copy the file contents to the RAM,
 * intead I've wrote some stupid functions to read character by
 * character using `fgetc` and doing the operations based on that, the problems
 * are: the functions I wrote won't be useful in many situations, since I would
 * have to rewrite another version of them to work with character arrays, and
 * these functins would make a lot of unnecessary I/O operations. In the next
 * version of the code, I will implement new functions to copy the
 * file contents into the RAM before doing any operations.
 */
int main(int argc, char *argv[])
{
	FILE* file;

	if (argc == 2) {
		file = fopen(argv[1], "r");

		if (!file) {
			printf("simp: cannot open file '%s'\n"
			       "No such file or directory.\n",
			       argv[1]);
			return EOF;
		} else {
			/* main routine */
			puts("syntax check ALPHA 0.1 - test routine\n");

			puts("Line 1: ");
			fprintl(1, file);
			printf("\n");

			puts("Line 2: ");
			fprintl(2, file);
			printf("\n");

			puts("Line 4: ");
			fprintl(4, file);
			printf("\n");

			fclose(file);
		}
	} else {
		puts("simp: missing file operand\n"
		     "Try 'simp --help' for more information.");
		return EOF;
	}

	return 0;
}

/*
 * fseekl: return line initial position
 *
 * positive number (character position) upon success, EOF on failure
 */
int fseekl(int lc, FILE *st)
{
	int i, c;

	if (!st)
		return EOF;

	rewind(st);

	for (i = 0; lc > 1; --lc) {
		while ((c = fgetc(st)) > 0 && c != '\n')
			++i;

		if (c < 0)
			/*
			 * FIXME: variable is not set to EOF.
			 * NOTE: I'm leaving this fix alone since I wont's reuse this code.
			 */
			return EOF;
		else
			++i; /* go after the newline */
	}

	return i;
}

/*
 * fgetl: read line from the given file stream, do not store newline character
 *
 * `str` on success, null pointer on failure
 */
char *fgetl(char *s, int lc, FILE *st)
{
	int i;

	if (!st)
		return NULL;

	i = fseekl(lc, st); /* find line start position */
	if (i < 0)
		return NULL;

	for (i = 0; (s[i] = fgetc(st)) > 0 && s[i] != '\n'; ++i)
		;
	/* put a null terminator in the end of the line */
	if (s[i] == '\n' || s[i] == '\0')
		s[i] = '\0';

	return s;
}

/*
 * fprintl: print a line from a file
 */
void fprintl(int ln, FILE *fp)
{
	char buf[BUFLEN];

	fgetl(buf, ln, fp);

	puts(buf);
}
