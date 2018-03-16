#include <stdio.h>
#include <ctype.h>
#include "jfile.h"

jfile::jfile(char *filename, const char *mode)
{
	srcfp = fopen(filename,mode);
	is_file = true;
}

jfile::jfile(const char *mode)
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

int jfile::get_char()
{
	return fgetc(srcfp);
}

int jfile::unget_char(char ch)
{
	return ungetc(ch,srcfp);
}

void jfile::skip_to_end_of_line()
{
    int ch;
    while ((ch= get_char()) != '\n')
   	;
}

void jfile::rewind_file()
{
    rewind(srcfp);
}

int jfile::get_int()
{
	int k;
        if (fscanf(srcfp,"%d",&k)!=1)
		return -1;
	return k;
}

jfile::~jfile()
{
	if (is_file && srcfp != NULL)
		fclose(srcfp);
}
