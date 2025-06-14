#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;
    int moves;
    const vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

public:
    TicTacToe() {
        board = vector<char>(9, ' ');
        currentPlayer = 'X';
        moves = 0;
    }

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << (board[i] == ' ' ? '.' : board[i]);
            if ((i + 1) % 3 == 0)
                cout << "\n";
            else
                cout << " | ";
        }
        cout << "\n";
    }

    bool makeMove(int pos) {
        if (pos < 0 || pos >= 9) {
            cout << "Invalid move: Out of bounds\n";
            return false;
        }

        if (board[pos] != ' ') {
            cout << "Invalid move: Cell already taken\n";
            return false;
        }

        board[pos] = currentPlayer;
        moves++;

        if (checkWinner()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            return true;
        }

        if (moves == 9) {
            printBoard();
            cout << "It's a tie!\n";
            return true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return false;
    }

    bool checkWinner() {
        for (const auto& pattern : winPatterns) {
            if (board[pattern[0]] == currentPlayer &&
                board[pattern[1]] == currentPlayer &&
                board[pattern[2]] == currentPlayer) {
                return true;
            }
        }
        return false;
    }

    void reset() {
        board.assign(9, ' ');
        currentPlayer = 'X';
        moves = 0;
    }

    void startGame() {
        cout << "Welcome to Tic Tac Toe!\n";
        printBoard();

        while (true) {
            int pos;
            cout << "Player " << currentPlayer << ", enter position (0-8): ";
            cin >> pos;

            bool gameOver = makeMove(pos);
            printBoard();

            if (gameOver) {
                char again;
                cout << "Play again? (y/n): ";
                cin >> again;
                if (again == 'y' || again == 'Y') {
                    reset();
                    printBoard();
                } else {
                    break;
                }
            }
        }
    }
};
