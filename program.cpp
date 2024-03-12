#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

class TicTacToe {
private:
    int board[3][3];
    int currentPlayer;  // 1 for Player 1, 2 for Player 2

public:
    TicTacToe() {
        currentPlayer = 1;
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
		board[i][j] = 0;
	    }
	}
    }

    inline void displayBoard() {
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
                cout << setw(2) << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "-----------------\n";
        }
    }

    inline int isMoveValid(int row, int col) {
	if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0){
	    return 0;
	}
	return 1;
    }

    inline int isGameWon() {
	// Check rows, columns, and diagonals for a win
	for (int i = 0; i < 3; i++) {
	    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
		return 0;
	    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
		return 0;
	}
	if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
	    return 0;
	if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
	    return 0;
	return 1;
    }

    inline int isBoardFull() {
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
		if (board[i][j] == 0)
		    return 1;
	    }
	}
	return 0;
    }

    inline void makeMove(int row, int col) {
	if (isMoveValid(row, col)==0) {
	    board[row][col] = currentPlayer;
	    currentPlayer = (currentPlayer == 1) ? 2 : 1;
	}
    }

    friend void playGame(TicTacToe &game);
};

inline void playGame(TicTacToe &game) {
    int row, col;
    int gameOver = 0;

    cout << "Welcome to Tic-Tac-Toe!\n";
    game.displayBoard();

    int currentPlayerChoice;
    cout << "Enter 1 to go first or 2 to go second: ";
    cin >> currentPlayerChoice;

    if (currentPlayerChoice == 2) {
	game.currentPlayer = 2;
    }

    while (gameOver!=1) {
	cout << "Player " << game.currentPlayer << "'s turn\n";
	cout << "Enter row and column (0-2): ";
	cin >> row >> col;

	if (game.isMoveValid(row, col) == 0) {
	    game.makeMove(row, col);
	    game.displayBoard();
	    if (game.isGameWon()==0) {
		cout << "Player " << game.currentPlayer << " wins!\n";
		gameOver = 1;
	    } else if (game.isBoardFull()==0) {
		cout << "It's a draw!\n";
		gameOver = 1;
	    }
	} else {
	    cout << "Invalid move. Try again.\n";
	}
    }
}

int main() {
    TicTacToe  game;
    clrscr();
    playGame(game);
    getch();
    return 0;
}
