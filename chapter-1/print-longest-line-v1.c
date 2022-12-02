#include <stdio.h>

#define MAX 1000
#define IN  1 /* inside limit */
#define OUT 0 /* outside limit */

int getsline(char line[], int maxline);
void copy(char to[], char from[]);

/*
 * Wesley V. Santos Jr.
 * print longest line - v1
 *
 * read the input and print the longest line
 *
 * NOTE: you must know that I spent almost a month trying to make this shit
 * work! The book says it must print "...as much as possible of the text..." and
 * also shows "...the length of arbitrarily long input lines..." but it's
 * impossible to do both changing only "the main routine", today when I finally
 * found a way to print lines longer than the MAX defined limit my program was
 * buggy and it just didn't look right, so I decided to do more research about
 * this exercise (and yes, I already did this before, so many times).
 * I finally found out what the autor was trying to say with "as much as
 * possible", thank you Kernighan and Ritchie for making me learn by suffering!
 */
int main()
{
	int state;         /* IN/OUT of limit */
	int len, max;      /* current length and maximum length seen so far */
	int c;             /* count extra characters */
	char line[MAX];    /* current line */
	char longest[MAX]; /* longest line */

	len = max = 0;
	state = IN;

	while ((len = getsline(line, MAX)) > 0) {
		if (len >= MAX-1 && line[len] != '\n')
			state = OUT;
		else
			state = IN;

		/* continue counting characters whether outside the limit */
		if (state == OUT)
			while ((c = getchar()) != '\n' && c != EOF)
				++len;

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	/*
	 * replace unwanted chars with a null char to print the line correctly, and
	 * also reduce 'max' by one to show it correctly
	 */
	if (longest[max-1] == '\n') {
		longest[max-1] = '\0';
		--max;
	}

	if (max > 0) {
		printf("\n\nLongest line length: %d\nLongest line content: %s\n", max, longest);
		/* indicates whether the line is longer than the limit */
		if (state == OUT)
			printf("...\n");
	}

	return 0;
}

/*
 * getsline: read a line into '*s', return length
 */
int getsline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/*
 * copy: copy a string to another
 */
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}
