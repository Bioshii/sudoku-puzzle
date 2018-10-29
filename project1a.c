//  board—a 9 by 9 array of integers that represents the current state of the puzzle, where 0 indicates a blank square 
//  start—a 9 by 9 array of boolean values that indicates which squares in board are given values that cannot be changed and the following methods:  

#include<stdio.h>
#include<stdlib.h>



// Sets the given square to the given value as an initial value that cannot be changed by the puzzle solver
void addInitial(int board[][9], int row, int col, int value) {
	// This conditional will always be true, but to stop the error from being emitted
	if (row < 9 && row > -1 && col > -1 && col < 9)
		board[row][col] = value;
}

// A function that creates an empty puzzle
void createSudokuPuzzle(int board[9][9], int defaultBoard[9][9], int start[9][9]) {
	int hereIsGood[30]; // An array holding temp coordinates that will be used for default given values in game

	// Fill in the board with default values of 0
	// For start array: 0 - false, 1 - true. Acts like boolean array
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			defaultBoard[i][j] = 0;
			board[i][j] = 0;	
			start[i][j] = 1;
		}
	}

	for (int i = 0; i < 30; i++) {
		// What I'm doing here is, I'll generate a number between 0 and 100. How this applys to a board is:
		// Every position is between 0 and 9 for columns and 0 and 9 for rows. Thsi means, a coordinate is always between
		// 0, 0 and 9,9. Through this, the tens place can eb found and the ones place can be found to develop a coordinate point.
		hereIsGood[i] = rand() % 100;
		int x = hereIsGood[i] / 10;
		int y = hereIsGood[i] % 10;

		start[x][y] = 0;
			
		int gotItIn = 0;
			
		while(!gotItIn) {
			int value = rand() % 10;
			//int *valid = getAllowedValues(board, x, y); 	
				
			//int checkingHere = value + valid;
			//if (*valid) { //Uncomment this for real program
			if (gotItIn == 0) { // Remove for real testing
				// addInitial(board, x, y, value); //Uncomment this for real program
				addInitial(board, x, y, 3); // Remove for real testing
				addInitial(defaultBoard, x, y, 3);
				gotItIn = 1;
			}
		    //}
				 
		}
	}
}
	



// Displays the puzzle that can be printed
void display(int board[][9]) {
	// Print the board
	printf("\n");
	for (int i = 0; i < 9; i++) {
		// If this is the first line, print the equal sign border

		// Print the contents of the board
		for (int j = 0; j < 9; j++) {
			if (j == 2 || j == 5) {
				printf("   %d\t|", board[i][j]);
			} else {
				printf("   %d\t", board[i][j]);
			}
		}
		printf("\n");


		// If this is the last line print the bottom equal sign border
		if (i == 8) {
		} else if (i == 2 || i == 5) {
			printf(" ");
			for (int h = 1; h < 69; h+= 2) {
				printf(" -");
			}
			printf("\n");
		}
		printf("\n");
}



void main() {
	// Variable controlling whether or not the user is done
	int done = 0;

	// Game loop itself
	while (!done) {
		// Sipmle introduction for the user.
		
		printf("Welcome to this game of Sudoku.\n");
		printf("Rules are simple.\n");
		printf("Fill the board up with numbers. The row, column, or 3x3 square can have the same number within it.\n");
		printf("Hint: 0 represents an empty square\n");

		int board[9][9]; // The board that will be used in the game
		int defaultBoard[9][9];
		int start[9][9];
		createSudokuPuzzle(board, defaultBoard, start);
		/*
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				board[i][j] = 1;
			}
		}
		*/

		display(board);

		

		done = 1;
	}

	return;

}
