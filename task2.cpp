#include <iostream>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char currentPlayer = 'O';

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid move, please try again!" << endl;
        return false;
    }
    if (board[row][col] != ' ') {
        cout << "That spot is already taken, please try again!" << endl;
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

int main() {
    int row, col;
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    drawBoard();
    while (!checkWin()) {
        cout << "It's " << currentPlayer << "'s turn. Please enter row and column numbers (0-2) to make your move: ";
        cin >> row >> col;
        if (makeMove(row, col)) {
            drawBoard();
            switchPlayer();
        }
    }
    cout << "Player " << currentPlayer << " loss!" << endl;
    return 0;
}