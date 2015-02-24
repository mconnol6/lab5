/* Mary Connolly
 * Lab 5
 * Puzzle class interface and implementation
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <class T>
class Puzzle{

	template <class S>
	friend ostream &operator << (ostream &output, Puzzle<S> &myPuzzle);
	
	public:
		Puzzle();
		void printPuzzle();
		void setCell(int, int, T);
		T getCell (int, int);
		int getSizeOfBoard();
		int isBoardFull(); //returns 1 if board is full

	private:
		vector<vector <T> > puzzle;
		int sizeOfBoard;

};

//returns 1 if the board is full and 0 if there are 0's present on the board
template<class T>
int Puzzle<T>::isBoardFull()
{
	//iterates through each cell
	for (int i = 0; i<sizeOfBoard; i++)
	{
		for (int j = 0; j<sizeOfBoard; j++)
		{
			if (puzzle[i][j] == 0)
			{
				return 0;
			}
		}
	}

	return 1;
}

template<class T>
int Puzzle<T>::getSizeOfBoard()
{
	return sizeOfBoard;
}

//returns the value of the cell in row a and column b
template <class T>
T Puzzle<T>::getCell(int a, int b)
{
	return puzzle[a][b];
}

//sets the value of the cell at row a and column b as input cell
template <class T>
void Puzzle<T>::setCell(int a, int b, T cell)
{
	puzzle[a][b] = cell;
}

//constructor
template <class T>
Puzzle<T>::Puzzle()
{
	sizeOfBoard = 9;

	string fileName;
	cout << "Please enter a file name: "; //ask user for filename
	cin >> fileName;

	ifstream inFile;
	inFile.open(fileName.c_str()); //open file

	vector<T> tempVec; //temporary vector
	T tempVar; //temporary variable

	while(!inFile.eof()) //loop until the end of the file
	{
		for (int i=0; i<sizeOfBoard; i++)
		{
			inFile >> tempVar; //save to tempVar
			tempVec.push_back(tempVar); //add temVar to tempVec
		}

		puzzle.push_back(tempVec); //add tempVec to puzzle, a vector of vectors
		tempVec.clear(); //clear tempVec
	}
}

//print board for user
template <class T>
void Puzzle<T>::printPuzzle()
{
	for (int i=0; i<sizeOfBoard; i++)
	{
		for (int j=0; j<sizeOfBoard; j++)
		{
			cout << puzzle[i][j] << " ";
		}

		cout << endl;
	}
}	


//overload << operator to call the printPuzzle member function
template <class S>
ostream &operator << (ostream &output, Puzzle<S> &myPuzzle)
{
	myPuzzle.printPuzzle();
}
