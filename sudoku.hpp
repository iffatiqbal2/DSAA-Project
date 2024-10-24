#include <iostream>
////#include <windows.h>
//#include <vector>
//#include<cctype>
//#include <stack>
//#include<fstream>
//#include<stdlib.h>
//#include<conio.h>
////#include<unistd.h>
//#include <cstdlib>
//#include <cstring>
#include<ctime>
using namespace std;
const int n = 9;

class Sudoku {
	int board[n][n];
public:
    
    void printBoard(int grid[n][n]) {
        system("cls");
        cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;
        cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
        cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (col == 3 || col == 6)
                    cout << " | ";
                cout << grid[row][col] << " ";
            }
            if (row == 2 || row == 5) {
                cout << endl;
                for (int i = 0; i < n; i++)
                    cout << "---";
            }
            cout << endl;
        }
    }

    bool isRight(int board[n][n], int row, int col, int num) {
        for (int i = 0; i < n; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + boxRowStart][j + boxColStart] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudoku(int board[n][n], int row, int col) {
        if (row == n - 1 && col == n)
            return true;

        if (col == n) {
            row++;
            col = 0;
        }

        if (board[row][col] != 0)
            return solveSudoku(board, row, col + 1);

        for (int num = 1; num <= 9; num++) {
            if (isRight(board, row, col, num)) {
                board[row][col] = num;

                if (solveSudoku(board, row, col + 1))
                    return true;

                board[row][col] = 0;
            }
        }
        return false;
    }

    bool isSolvedCompletely(int grid[n][n]) {
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                if (grid[row][col] == 0)
                    return false;

        return true;
    }
void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n') {
    }
}

void playGame(int board[n][n]) {
    int row, col, num;
    while (true) {
        printBoard(board);
        cout << endl << endl;
        cout << "ENTER -1 TO SEE SOLVE SUDOKU" << endl;

        do {
            cout << "\nENTER ROW: ";
            cin>>row;
            if(row==-1){
                solveSudoku(board, 0, 0);
                printBoard(board);
                cout << endl;
                cout << "Better luck next time!!!" << endl;
                return;
			}
            else if (cin.fail() || row < 1 || row > n) {
                cout << "Invalid input. Please enter a number between 1 and " << n << "." << endl;
                cin.clear();  // Clear the error state
                clearInputBuffer();  // Manually clear the input buffer
            }
        } while (row < 1 || row > n);

        do {
            cout << "\nENTER COLUMN: ";
            cin>>col;
            if(col==-1){
                solveSudoku(board, 0, 0);
                printBoard(board);
                cout << endl;
                cout << "Better luck next time!!!" << endl;
                return;
			}
            else if (cin.fail() || col < 1 || col > n) {
                cout << "Invalid input. Please enter a number between 1 and " << n << "." << endl;
                cin.clear();  // Clear the error state
                clearInputBuffer();  // Manually clear the input buffer
            }
        } while (col < 1 || col > n);
        
        do {
            cout << "\nENTER NUMBER: ";
            cin>>num;
            if(num==-1){
                solveSudoku(board, 0, 0);
                printBoard(board);
                cout << endl;
                cout << "Better luck next time!!!" << endl;
                return;
			}
            else if (cin.fail() || num < 1 || num > 9) {
                cout << "Invalid input. Please enter a number between 1 and " << n << "." << endl;
                cin.clear();  // Clear the error state
                clearInputBuffer();  // Manually clear the input buffer
            }
        } while (num < 1 || num > 9);

        if (isSolvedCompletely(board))
            break;

        row--;
        col--;

        if (!isRight(board, row, col, num)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = num;
    }

    bool solved = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                solved = false;
                break;
            }
        }
    }

    if (solved) {
        cout << "Congratulations! You have solved the puzzle." << endl;
        printBoard(board);
    } else {
        cout << "Puzzle not solved. Better luck next time." << endl;
    }
}

};

