#include <stdio.h>
#include "jfile.h"
#include "jsolver.h"


Puzzle::Puzzle(char *filename)
{
	initialisation_puzzle_by_null();
	jfile fp(filename,"r");
	int nrow,ncol;

	n[row] = get_numbers_of_rows(fp);
	fp.skip_to_end_of_line();
	n[col] = get_numbers_of_rows(fp);
	fp.rewind_file();
	get_structure_of_lines(fp,row);
	fp.skip_to_end_of_line();
	get_structure_of_lines(fp,col);
	fp.rewind_file();
	get_data_of_rows(fp,row);
	fp.skip_to_end_of_line();
	get_data_of_rows(fp,col);
}

void Puzzle::initialisation_puzzle_by_null()
{
	for (int dir=0;dir<n_orientations;dir++)
	{
		n_clues[dir]=NULL;
		for(int line_dir=0;line_dir<n_line_dirs;line_dir++)
		{
			clue[dir][line_dir]=NULL;
			board[dir][line_dir]=NULL;
		}
	}
}

int Puzzle::get_numbers_of_rows(jfile &fp)
{
	char ch;
	int n;
        n=0;
        while ((ch = fp.get_char())!='#')
        {
                fp.skip_to_end_of_line();
                n++;
        }
	return n;

}

void Puzzle::get_structure_of_lines(jfile &fp,const int orientation)
{
	int n_lines = n[orientation];
	int **clue_lines;
	int *n_clues_of_lines;
	int i,j,k;

	init_clue_lines_by_null(orientation, forward);
	clue_lines = clue[orientation][forward];
	n_clues_of_lines = n_clues[orientation];

        for (i=1;i<n_lines+1;i++)
        {
                j =0;
                do
                {
                        k = fp.get_int();
                        if (k !=0)
                        {
                                j++;
                        }

                }
                while (k != 0);
                n_clues_of_lines[i+1] = j+2;
		clue_lines[i+1] = new int[n_clues_of_lines[i+1]];
                fp.skip_to_end_of_line();
        }
}


void Puzzle::init_clue_lines_by_null(const int orientation, const int line_dir)
{
	int n_lines = n[orientation];

	clue[orientation][line_dir] = new int*[n_lines +2];
	n_clues[orientation] = new int[n_lines +2];

	for(int i=0;i<n_lines+2;i++)
	{
		clue[orientation][line_dir][i] = NULL;
	}
}


void Puzzle::get_data_of_rows(jfile &fp,const int orientation)
{
	int nrow = n[orientation];
	int **clue_row;
	int *n_clues_row;
	int i,j,k;

	clue_row = clue[orientation][forward];
	n_clues_row = n_clues[orientation];

        for (i=1; i< nrow+1;i++)
        {
                for (j=1;j<n_clues_row[i+1]+1;j++)
                {
                        k = fp.get_int();
                        clue_row[i+1][j] = k;
                }
                fp.skip_to_end_of_line();
        }
}
