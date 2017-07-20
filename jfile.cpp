#include <stdio.h>
#include <ctype.h>
#include "jfile.h"

jfile::jfile(char *filename, char *mode)
{
	srcfp = fopen(filename,mode);
	is_file = true;
}

jfile::jfile(char *mode)
{
	if (mode=="r")
	{
		srcfp = stdin;
	}
	else
	{
		srcfp = stdout;
	}
	is_file = false;
}

int jfile::sread_pint(int newline)
{
    int ch, n= 0;

    /* Skip leading spaces and commas, but not newlines if newline is true */
    while ((ch= fgetc(srcfp)) != EOF && (isspace(ch) || ch == ','))
	if (newline && ch == '\n') return -3;
    if (ch == EOF) return -2;
    if (!isdigit(ch)) return -1;

    /* Read in the number */
    do {
	if (ch == EOF) return -2;
    	n= n*10 + ch - '0';
    } while (isdigit(ch= fgetc(srcfp)));
    if (ch != EOF) ungetc(ch,srcfp);

    return n;
}

