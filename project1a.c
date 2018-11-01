//  board—a 9 by 9 array of integers that represents the current state of the puzzle, where 0 indicates a blank square 
//  start—a 9 by 9 array of boolean values that indicates which squares in board are given values that cannot be changed and the following methods:  

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a = 5;

void addGuess(int start[][9],int board[][9], int row, int col, int value){
    if (start[row][col]){
        board[row][col]=value;
    }
}

int checkPuzzle(int board[][9]){
    int i,j,k,l,m,n;
	
	// i = row
	// j = index of first value
	// k = index of 2nd value
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=j+1;k<9;k++){
            if (board[i][j] != 0 && board[i][k] != 0 && board[j][i] != 0 && board[k][i] != 0 && (board[i][j]==board[i][k]||board[j][i]==board[k][i])) {
                return 0;
			}
			}
        }
    }

    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            for(k=i;k<3;k++){
                for(l=j;l<3;l++){
                    for(m=k;m<3;m++){
                        for(n=l;n<3;n++){
                            if(k!=m||n!=l&&board[k][l]==board[m][n] && board[k][l] != 0 && board[m][n] != 0){
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
// Idk if you want me to do the functions, so getAllowedValues can take a piece from checkpuzzle, and I think checkPuzzle can be changed a bit

int checkValue(int board[][9], int row, int col, int value) {
	// i: will refer to row (aka x value)
	// j: will refer to col (aka y value)
	int i = row;
	int j = col;
	for (int k = 0; k < 9; k++) {
		// Check per row
		if (board[i][k] == value && k != j) {
			return 0;
		}
				
		// Check per col
		if (board[k][j] == value && k != i) {
			return 0;
		}
	}

	int startRow;
	int startCol;

	if(row < 3) {
		startRow = 0;
	} else if (row < 6) {
		startRow = 3;
	} else {
		startRow = 6;
	}

	if (col < 3) {
		startCol = 0;
	} else if (row < 6) {
		startRow = 3;
	} else {
		startCol = 6;
	}

	for (int m = startRow; m < startRow + 3; m++) {
		for (int n = startCol; n < startCol + 3; n++) {
			if(board[m][n] == value) {
				return 0;
			}
		}
	}

	return 1;
}
	


int getValueIn(int board[9][9], int row, int col){
    return board[row][col];
}

int isFull(int board[9][9]){
    int i, j;
    for(i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if (board[i][j]==0){
                return 0;
            }
        }
    }
    return 1;
}


void reset(int defaultBoard[9][9], int board[9][9]){
    board = defaultBoard;
}

void getAllowedValues(int board[][9], int row, int col, int arr[]){
    int i;

    for(i=1;i<=9;i++){
        if(checkValue(board, row, col, i)){
		//if(checkPuzzle(board)) {
			printf("We workin\n");
            arr[i-1]=1;
        }else{
            arr[i-1]=0;
        }
    }

	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("Finished hi\n");
}

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
		//srand(time(NULL));
		hereIsGood[i] = rand() % 100;
		int x = hereIsGood[i] / 10;
		int y = hereIsGood[i] % 10;

		start[x][y] = 0;
			
		int gotItIn = 0;
		int valid[9];
			
		while(!gotItIn) {
			int value = (rand() % 9) + 1; 
			printf("Hi\n");
			getAllowedValues(board, x, y, valid);
			printf("Hi2\n");

			
			printf("Value %d is %d\n", value, valid[value]);
		
				
			if (valid[value-1]) { //Uncomment this for real program
				addInitial(board, x, y, value); //Uncomment this for real program
				addInitial(defaultBoard, x, y, value);
				gotItIn = 1;
			}
				 
		}
		printf("Loop!\n");
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
}



void main() {
	// Variable controlling whether or not the user is done
	int done = 0;
	srand(time(NULL));

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

		int gameStillGoing = 1;
		
		display(board);
		while (gameStillGoing) {
			printf("\n\n");
			int x, y, z;
		//	printf("Would you like to see allowed values for a specific coordinate? ");
		//	printf("1. Yes\n 2. No\n");

//			int seeValues = 0;
//			scanf("%d", &seeValues)
			
			printf("Enter the x coord: ");
			scanf("%d", &x);
			x = (x-9);
			if (x < 0) {
				x *=1;
			}

			printf("Enter the y coord: ");
			scanf("%d", &y);

			printf("Enter the value you would like to put in: ");
			scanf("%d", &z);

			addGuess(start, board, y, x, z);
				
			display(board);
			printf("\n\n");

			if(! checkValue(board, y, x, z)) {
			//if(! checkPuzzle(board)) {
				printf("This value will not work. Feel free to change it.\n");
			}

			
			if(isFull(board) && checkPuzzle(board)) {
				printf("\nYou win!\n");
				gameStillGoing = 0;
			} else if(isFull(board) && ! checkPuzzle(board)) {
				printf("\nYou lose!\n");
				printf("Would you like to reset the board and try again?");
				printf("1. Yes\n2. No\n");
				int userChoice = 0;
				if (userChoice == 1) {
					reset(defaultBoard, board);
					printf("Reset!\n");
				} else {
					printf("Cya!\n");
					gameStillGoing = 0;
				}
			}

		}

		printf("Would you like to play again?\n");
		printf("1. Yes\n");
		printf("2. No\n");

		scanf("%d", &done);

		if(done == 1)
			done = 0;
		else
			done = 1;

		reset(defaultBoard, board);
	}

	return;
}
