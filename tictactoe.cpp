#include <iostream>
using namespace std;

// Helper function to display the current 3x3 game board
void printBoard(const char board[3][3]) {
    cout << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
    cout << endl;
}

//A helper function to ask the user if they want to play again
bool askPlayAgain() {
    char choice;
    while (true) {
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = tolower(static_cast<unsigned char>(choice));

        if (choice == 'y') {
            return true;
        } 
        else if (choice == 'n') {
            return false;
        } 
        else {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
        }
    }
}


int main() {

    do{
            // Initialize an empty 3x3 board
    char board[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int r = -1;
    int c = -1;
    char winner = ' ';

    // A Tic-Tac-Toe game has a maximum of 9 turns
    for (int i = 0; i < 9; i++) {
        printBoard(board);

        // Stop the game early if a winner was found on the previous turn
        if (winner != ' ') {
            break;
        }

        // Prompt the current player for a valid move
        cout << "Current Player is " << currentPlayer << endl;
        while (true) {
            cout << "Enter row and column (0-2) separated by a space: ";
            
            // Check if input is valid numbers within range and on an empty tile
            if (!(cin >> r >> c)) {
                cout << "Invalid input. Please enter two numbers." << endl;
            }
            else if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Out of bounds. Enter numbers from 0 to 2." << endl;
            }
            else if (board[r][c] != ' ') {
                cout << "Tile is already full, try again." << endl;
            }
            else {
                break; // Valid move received
            }

            // Reset variables and clear bad input from the buffer
            r = -1;
            c = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Place the player's mark on the board and switch turns
        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // Check rows (horizontal) for a win
        for (int row = 0; row < 3; row++) {
            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                winner = board[row][0];
                break;
            }
        }

        // Check columns (vertical) for a win
        for (int col = 0; col < 3; col++) {
            if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                winner = board[0][col];
                break;
            }
        }

        // Check both diagonals for a win
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }

    // Print the final board state (especially important if the game ends on turn 9)
    printBoard(board);

    // Announce the final game result
    if (winner != ' ') {
        cout << "Player " << winner << " is the winner!" << endl;
    }
    else {
        cout << "It's a Tie!" << endl;
    }

    

    } while(askPlayAgain());


    return 0;
}
