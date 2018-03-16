#ifndef JSOLVER_H_SENTRY
#define JSOLVER_H_SENTRY

enum{n_orientations=2};//number of orintations of a game board
enum{row,col}; //types of orientations

enum{n_line_dirs=2}; //number of line directions
enum{forward,backward}; //line direction. forward - solve line from left to right; backward - from right to left

enum{n_indexes=2};//number of indexs of game board

enum{unknown,black,white}; //Value of cells of game board

class Cell
{
	int index[n_orientations][n_line_dirs][n_indexes]; //indexes of cell on game board
	int value;
public:
	Cell(int i,int j,int new_value);
};

class Puzzle
{
	int n[n_orientations]; //number of rows and columns of a game board
	int **clue[n_orientations][n_line_dirs];
	int *n_clues[n_orientations];
	Cell ***board[n_orientations][n_line_dirs];

public:
	Puzzle(char *filename);
private:
	void initialisation_puzzle_by_null();
	int get_numbers_of_rows(jfile &fp);
	void get_structure_of_lines(jfile &fp,const int orientation);
	void init_clue_lines_by_null(const int orientation, const int line_dir);
	void get_data_of_rows(jfile &fp,const int orientation);
};


#endif
