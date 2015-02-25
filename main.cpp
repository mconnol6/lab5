/* Mary Connolly
 * Lab 5
 * driver file
 */

#include <iostream>
#include "sudoku.h"
using namespace std;

int main()
{
	Puzzle<int> myIntPuzzle; //create an int puzzle

	myIntPuzzle.printPuzzle(); //print puzzle for user

	Puzzle<char> myCharPuzzle; // char puzzle

	myCharPuzzle.printPuzzle(); //print puzzle for user
}
