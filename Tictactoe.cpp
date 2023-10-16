#include <iostream>
#include <vector>

// Function to print the Tic-Tac-Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    int row, col;
    int moves = 0;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true) {
        printBoard(board);
        std::cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        board[row][col] = currentPlayer;
        moves++;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        } else if (moves == 9) {
            printBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
