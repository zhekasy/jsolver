#ifndef JFILE_H_SENTRY
#define JFILE_H_SENTRY


class jfile
{	
	FILE *srcfp;
	bool is_file;
public:
	jfile(char *filename,char *mode);
	jfile(char *mode);
	int sread_pint(int newline);
	
};

#endif
