/* Mary Connolly
 * Lab 5
 * User can play a game of Sudoku
 */

#include <iostream>
#include "sudoku.h"
using namespace std;

int checkIfWon(Puzzle<int> &);
int checkOriginal(Puzzle<int> &);
void addNumber(Puzzle<int> &, Puzzle<int> &);
int checkIf1to9(int);
int checkCell(Puzzle<int> &, int, int, int, int);

int main()
{
	Puzzle<int> myPuzzle;
	Puzzle<int> originalPuzzle = myPuzzle; //keeps track of original input
	char c='y'; //get user input

	cout << myPuzzle;

	while(c!='q' && !myPuzzle.isBoardFull())
	{
		addNumber(myPuzzle, originalPuzzle);
		cout << myPuzzle;
		cout << "Press 'q' to quit and any key to continue: ";
		cin >> c;
	}

	if (checkIfWon(myPuzzle))
	{
		cout << "You solved the puzzle!" << endl;
	}

	else
	{
		cout << "You did not solve the puzzle." << endl;
	}
}

//check if user won
int checkIfWon(Puzzle<int> &myPuzzle)
{
	for (int i=0; i<myPuzzle.getSizeOfBoard(); i++)
	{
		for (int j=0; j<myPuzzle.getSizeOfBoard(); j++)
		{
			if (myPuzzle.getCell(i, j) == 0)
			{
				return 0;
			}
			if (!checkCell(myPuzzle, i, j, myPuzzle.getCell(i, j), 0))
			{
				return 0;
			}
		}
	}

	return 1;
}

//return 1 if the cell is 0 in the original puzzle
int checkOriginal(Puzzle<int> &original, int row, int col)
{
	if (original.getCell(row, col) != 0)
	{
		cout << "That cell is a part of the original puzzle." << endl;
		return 0;
	}

	return 1;
}

//check if number can be placed in the cell
int checkCell(Puzzle<int> &myPuzzle,  int row, int col, int n, int printError)
{
	for (int i = 0; i<myPuzzle.getSizeOfBoard(); i++)
	{
		if (n==myPuzzle.getCell(row, i) && row!=i)
		{
			if (printError)
			{
				cout << "The number is already in the row." << endl;
				return 0;
			}
		}

		if (n==myPuzzle.getCell(i, col) && col!=i)
		{
			if (printError)
			{
				cout << "The number is already in the column." << endl;
				return 0;
			}
		}
	}

	int x, y; //coordinates of top left corner of section in which cell lies

	if(row>=0 && row<=2)
	{
		x=0;

	}

	else if(row>=3 && row<=5)
	{
		x=3;
	}

	else
	{
		x=6;
	}


	if(col>=0 && col<=2)
	{
		y=0;
	}

	else if(col>=3 && col<=5)
	{
		y=3;
	}

	else
	{
		y=6;
	}

	for (int j = x; j<x+3; j++)
	{
		for (int k = y; k<y+3; k++)
		{
			if (n==myPuzzle.getCell(j, k) && row!=j && col!=k)
			{
				if (printError)
				{
					cout << "The number is already in the section." << endl;
					return 0;
				}
			}
		}
	}

	return 1;
}

//if input is not 1 to 9, asks user for new value; returns n
int checkIf1to9(int n)
{
	while (n<1 || n>9)
	{
		cout << "The number must be between 1 and 9: ";
		cin >> n;
	}

	return n;
}

void addNumber(Puzzle<int> &myPuzzle, Puzzle<int> &originalPuzzle)
{
	int col, row, num; //use to get user input

	cout << "Enter row (from 1 to 9): ";
	cin >> row;
	row = checkIf1to9(row);
	row--;

	cout << "Enter column (from 1 to 9): ";
	cin >> col;
	col = checkIf1to9(col);
	col--;

	cout << "Enter number (from 1 to 9): ";
	cin >> num;
	num = checkIf1to9(num);

	if (checkOriginal(originalPuzzle, row, col) && checkCell(myPuzzle, row, col, num, 1))
	{
		myPuzzle.setCell(row, col, num);
	}
}
