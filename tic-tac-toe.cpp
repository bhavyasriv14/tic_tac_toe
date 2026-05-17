#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    string player1Name, player2Name;
    int moveCount;

    void initBoard() {
        char num = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = num++;
        moveCount = 0;
    }

    void displayBoard() {
        cout << "\n";
        cout << "  +---+---+---+\n";
        for (int i = 0; i < 3; i++) {
            cout << "  | ";
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X')
                    cout << "X | ";
                else if (board[i][j] == 'O')
                    cout << "O | ";
                else
                    cout << board[i][j] << " | ";
            }
            cout << "\n  +---+---+---+\n";
        }
        cout << "\n";
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }

    bool checkDraw() {
        return moveCount == 9;
    }

    bool makeMove(int cell) {
        if (cell < 1 || cell > 9) {
            cout << "  [!] Invalid input. Enter a number between 1 and 9.\n";
            return false;
        }
        int row = (cell - 1) / 3;
        int col = (cell - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "  [!] Cell " << cell << " is already taken. Choose another.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        moveCount++;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    string getCurrentPlayerName() {
        return (currentPlayer == 'X') ? player1Name : player2Name;
    }

public:
    TicTacToe() {
        currentPlayer = 'X';
        initBoard();
    }

    void setPlayerNames() {
        cout << "  Enter name for Player 1 (X): ";
        cin >> player1Name;
        cout << "  Enter name for Player 2 (O): ";
        cin >> player2Name;
        cout << "\n  Welcome, " << player1Name << " (X) and " << player2Name << " (O)!\n";
    }

    void play() {
        setPlayerNames();

        while (true) {
            displayBoard();

            int cell;
            cout << "  " << getCurrentPlayerName() << " (" << currentPlayer << ") - Enter cell (1-9): ";

            if (!(cin >> cell)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "  [!] Invalid input. Please enter a number.\n";
                continue;
            }

            if (!makeMove(cell))
                continue;

            if (checkWin()) {
                displayBoard();
                cout << "  *** " << getCurrentPlayerName() << " (" << currentPlayer << ") wins! Congratulations! ***\n\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "  *** It's a draw! Well played by both! ***\n\n";
                break;
            }

            switchPlayer();
        }
    }

    void run() {
        cout << "\n";
        cout << "  ================================\n";
        cout << "        TIC TAC TOE - C++         \n";
        cout << "  ================================\n";
        cout << "  Cells are numbered 1-9:\n";
        cout << "  +---+---+---+\n";
        cout << "  | 1 | 2 | 3 |\n";
        cout << "  +---+---+---+\n";
        cout << "  | 4 | 5 | 6 |\n";
        cout << "  +---+---+---+\n";
        cout << "  | 7 | 8 | 9 |\n";
        cout << "  +---+---+---+\n\n";

        char choice;
        do {
            initBoard();
            currentPlayer = 'X';
            play();

            cout << "  Play again? (y/n): ";
            cin >> choice;
            cout << "\n";
        } while (choice == 'y' || choice == 'Y');

        cout << "  Thanks for playing! Goodbye.\n\n";
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}