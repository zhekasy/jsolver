#ifndef JFILE_H_SENTRY
#define JFILE_H_SENTRY


class jfile
{	
	FILE *srcfp;
	bool is_file;
public:
	jfile(char *filename,const char *mode);
	jfile(const char *mode);
	int get_char();
	int unget_char(char);
	void skip_to_end_of_line();
	int sread_pint(int newline);
	void rewind_file();
	int get_int();
	~jfile();
};

#endif
