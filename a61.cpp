/*
Assignment #6 Part #1 TIC TAC TOE
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;


// initialize takes a nine element gameBoard and doesn't return anything.
// It sets the elements of the gameBoard to integers from 1 to 9 starting
// from the upper left.
void initialize(int gameBoard[]) {
	
	//initialize the value in each postion to it's number
	gameBoard[0]=1;
	gameBoard[1]=2;
	gameBoard[2]=3;
	gameBoard[3]=4;
	gameBoard[4]=5;
	gameBoard[5]=6;
	gameBoard[6]=7;
	gameBoard[7]=8;
	gameBoard[8]=9;
	
}


// playCell takes a player (0 for "O", 1 for "X"), a position (1 to 9),
// and the nine element gameBoard, and returns true if the move is legal
// (i.e. that spot is not yet taken), and false otherwise.  If the move is
// legal it changes the position to that players number (10 for "O", 11 for "X").
// If the player or position input is invalid, it returns false;
bool playCell(int player, int position, int gameBoard[]) {
		
	if (player==0) { //see which player is it
		if (gameBoard[position]>9) { //see if the cell is above nine which means its taken already
			return false; //return that its taken	
		} else {
			gameBoard[position]=10; //if not taken, give that position to the player
			return true; //return its not taken
		}
	} else {
		if (gameBoard[position]>9) {//see if the cell is above nine which means its taken already
			return false;//return that its taken					
		} else {
			gameBoard[position]=11;//if not taken, give that position to the player
			return true;//return its not taken
		}
	}
}
enum Winner {
	Player1 = 0,
	Player2 = 1,
	NoOne = -1
};

Winner isWin(const int gameBoard[], int first, int second, int third) {
	if ( (gameBoard[first] == gameBoard[second]) && (gameBoard[second] == gameBoard[third]) ) {
		if (gameBoard[first] == 10) {
			return Player1;
		} else if (gameBoard[first] == 11) {
			return Player2;
		}
	}
}

// winCheck checks the gameBoard for a winner.
// Returns 0 if "O" has won; 1 if "X" has won; and -1 if no winner (yet).
// It assumes the board has only 1 winner.
// (the "const" indicates that we will not change the gameBoard in this function.)
int winCheck (const int gameBoard[]) {
	int possibleWins[8][3];
	possibleWins[0][0] = 0;
	possibleWins[0][1] = 1;
	possibleWins[0][2] = 2;
	
	possibleWins[1][0] = 3;
	possibleWins[1][1] = 4;
	possibleWins[1][2] = 5;
	
	possibleWins[2][0] = 6;
	possibleWins[2][1] = 7;
	possibleWins[2][2] = 8;
	
	possibleWins[3][0] = 0;
	possibleWins[3][1] = 3;
	possibleWins[3][2] = 6;
	
	possibleWins[4][0] = 1;
	possibleWins[4][1] = 4;
	possibleWins[4][2] = 7;
	
	possibleWins[5][0] = 2;
	possibleWins[5][1] = 5;
	possibleWins[5][2] = 8;
	
	possibleWins[6][0] = 0;
	possibleWins[6][1] = 4;
	possibleWins[6][2] = 8;
	
	possibleWins[7][0] = 2;
	possibleWins[7][1] = 4;
	possibleWins[7][2] = 6;
	
	for (int i = 0; i < 8; ++i) {
		Winner result = isWin(gameBoard, possibleWins[i][0], possibleWins[i][1], possibleWins[i][2]);
		if (result != NoOne) {
			return (int)result;
		}	
	}
	
	return -1;
}


// printBoard takes the gameBoard and doesn't return anything.
// It prints out the current state of the board to the display.
// (the "const" indicates that we will not change the gameBoard in this function.)
void printBoard(const int gameBoard[]) {
		
	cout << "\n+-----+-----+-----+\n|"; //print out line
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(3);
			if (gameBoard[i*3 + j]==10) { //check if that position has been taken by first player
				cout << "0" << "  |"; //print out which players takes that position
			} else if (gameBoard[i*3 + j]==11) {//check if that position has been taken by second player
				cout << "X" << "  |";//print out which players takes that position
			} else {
				cout << gameBoard[i*3 + j] << "  |"; //print out position if not taken
			}
		}
		cout << "\n+-----+-----+-----+\n";//print out line
		if (i < 2) {
			cout << "|";	
		}
	}	
}


// (getIntBP is an improved version of getInt written in Assignment #5, Question #1,
// as it is "bullet-proof".)
// Returns an integer value from the user between minimum and 
// maximum, inclusive.
// We assume that the calling function has output the initial 
// request for input.
// This function will check the value entered and output an error 
// message until a value in the correct range is entered.
// This function deals correctly with non-integer inputs.
int getIntBP(int minimum, int maximum) {
	
	int value;
    // loop until we get an integer value between minimum and maximum, inclusive
    cin >> value; //input value
    for(;;) {
        if (value>=minimum && value<=maximum) { //see if the value is within correct range
            return value/1; //make sure the value is an integer
        } else {
        	for (;;) {
        		cout << "Input must be an integer between " << minimum << " and " << maximum << " inclusive, try again: "; //tell user the value is invalid
        		cin >> value; //input new value
        		if (value>=minimum && value<=maximum) { //check if value is valid again
        			break; //finish if valid
        		}
        	}
        }
    }
    
}


int main() {
	
	char player[2];	// a character array 'O' or 'X'
	int move, // the move number: 0 to 8
		turn, //  0 = "O"'s turn; 1 = "X"'s turn
		playerFirst=0, // we start with "O" going first
		winPlayer; // 0 is "O", 1 is "X", -1 is no winner yet or tie
		
	int board[9]; // the tic-tac-toe board
	
	player[0]= '0';
	player[1]= 'X';
	
	// play until user enters 0 to stop
	for(;;) { 
		// initialize and print the board
		initialize(board);
		printBoard(board);
		
		// loop once for every turn (max of 9)
		for (move=0; move<9; move++) {
			
			turn = (move+playerFirst)%2; // 0 (O) or 1 (X)'s turn
						
			// that player makes a move
			for(;;){
				cout << "Player " << player[turn] << " choose cell to play in: ";
				if (playCell(turn,getIntBP(1,9),board)) {
					break;
				}
				cout << "Cell already used" << endl;
			} // end for
			
			printBoard(board);	// show the board
			
			// check for a winner if this is the fifth move or more (moves start at 0)
			if (move>3) {
				winPlayer=winCheck(board); // look for a winner if 5 or more moves
				if (winPlayer!=-1) { // we have a winner
					cout << "Player " << player[winPlayer] << " wins!\n\n";
					playerFirst=(winPlayer+1)%2; // other player goes first next time
					break; // this game is over
				}//end if
			}//end if
		} // end for move
		
		// check for no winner
		if (winPlayer==-1){		// no one won
			cout << "Game is a draw.\n\n";
			playerFirst=(playerFirst+1)%2;	// Flip the first player for next game
		} // end if
		
		cout << "Do you wish to play again (Enter 1 for Yes or 0 for No)?: ";
		// if user enters 0, we exit, otherwise continue
		if (!getIntBP(0,1)) {
			break;
		}
	} // end for
	
	system ("PAUSE"); return 0;

} // end main

