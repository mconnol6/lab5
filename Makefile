all: main playSudoku

playSudoku: playSudoku.cpp sudoku.h
	g++ playSudoku.cpp -o playSudoku

main: main.cpp sudoku.h
	g++ main.cpp -o main

clean:
	rm *.o main playSudoku
