#ifndef JSOLVER_H_SENTRY
#define JSOLVER_H_SENTRY

enum{n_orientations=2};//number of orintations of a game board
enum{row,col}; //types of orientations

enum{n_line_dir=2}; //number of line directions
enum{forward,backward}; //line direction. forward - solve line from left to right; backward - from right to left

enum{unknown,black,white}; //Value of cells of game board

class Cell
{
public:
	int value;
}

class Puzzle
{
	int n[n_orientations]; //number of rows and columns of a game board
	int **clue[n_orientations][n_line_dir];
	int *n_clues[n_orientations];

public:
	Puzzle(char *filename);

};


#endif
