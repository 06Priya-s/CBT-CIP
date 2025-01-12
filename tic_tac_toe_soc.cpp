#include <iostream>
#include <windows.h>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char turn = 'X';
int row, col;
bool draw = false;

void displayBoard() {
    system("cls");
    cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "\t\t+    T I C K \t  T A C  \t  T O E  \t +\n";
    cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    cout << "\t\t\t  <MULTIPLAYER GAME>\n\n";
    cout << "\tPlayer1 [X]\n\tPlayer2 [O]\n\n";
    
    cout << "\t\t\t=================\n";
    for (int i = 0; i < 3; ++i) {
        cout<<"\t\t\t     |     |     ";
        cout << "\n\t\t\t  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
        if (i < 2) 
            cout << "\t\t\t_____|_____|_____\n";
        else 
            cout << "\t\t\t     |     |     \n";
    }
    cout << "\t\t\t=================\n";
}

void playerTurn() {
    int choice;
    cout << "\n\tPlayer " << (turn == 'X' ? "1 [X]" : "2 [O]") << " turn: ";
    cin >> choice;

    switch (choice) {
    case 1: row = 0; col = 0; break;
    case 2: row = 0; col = 1; break;
    case 3: row = 0; col = 2; break;
    case 4: row = 1; col = 0; break;
    case 5: row = 1; col = 1; break;
    case 6: row = 1; col = 2; break;
    case 7: row = 2; col = 0; break;
    case 8: row = 2; col = 1; break;
    case 9: row = 2; col = 2; break;
    default:
        cout << "Invalid choice! Try again.\n";
        playerTurn();
        return;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Please try again.\n";
        playerTurn();
    }
    displayBoard();
}

bool isGameOver() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) 
            return false;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) 
            return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) 
        return false;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) 
        return false;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main() {
    displayBoard();
    while (isGameOver()) {
        playerTurn();
    }
    if (draw) {
        cout << "Game Draw!!!\n";
    } else {
        if (turn == 'X') {
            cout << "Player 2 [O] wins!!! Congratulations\n";
        } else {
            cout << "Player 1 [X] wins!!! Congratulations\n";
        }
    }
    return 0;
}

