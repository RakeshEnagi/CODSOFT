#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    currentPlayer = 'X';
}

void printBoard() {
    system("clear"); // use "cls" if on Windows
    cout << "\n     TIC-TAC-TOE GAME 🎮\n";
    cout << "     Player 1: X  |  Player 2: O\n\n";
    cout << "         1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << "      " << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n        ---|---|---\n";
    }
    cout << "\n\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    bool gameOver = false;
    initializeBoard();

    while (!gameOver) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column between 1-3): ";
        cin >> row >> col;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n❌ Invalid input! Please enter numeric values.\n";
            continue;
        }

        row--; col--;
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "\n❌ Invalid move! Please enter numbers between 1 and 3.\n";
            continue;
        }
        if (board[row][col] != ' ') {
            cout << "\n⚠️ That spot is already taken. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            printBoard();
            cout << "🏆 Player " << currentPlayer << " wins! Congratulations!\n";
            gameOver = true;
        } else if (checkDraw()) {
            printBoard();
            cout << "🤝 It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y')
            cin.ignore(1000, '\n');
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n👋 Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
