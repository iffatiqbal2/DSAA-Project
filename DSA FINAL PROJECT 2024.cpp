#include <iostream>
//#include <windows.h>
#include"sudoku.hpp"
#include"card.hpp"
#include"wordChain.hpp"
#include"tictactoe.hpp"
#include"wordPuzzle.hpp"
#include"guessingGame.hpp"
#include <vector>
#include<cctype>
#include <stack>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include <cstdlib>
#include <cstring>
#include<ctime>
using namespace std;

int main(){
	system("COLOR 70");
	char x='n';
	do{
    system("cls");
     cout<<"\n\t ______   _____   _       _   _____     ______   _____   _     _     ____   ____     _   _          ";
     cout<<"\n\t|  ____| | [_] | | |_____| | |  ___|   |  ____| | [_] | | |   | |   |  __| | [_]|   | | | |         ";
     cout<<"\n\t| |   _  |  _  | |  _   _  | | |___    | |   _  |  _  | | |   | |   | |__  |  _ |   | |_| |         ";
     cout<<"\n\t| |__| | | | | | | | | | | | | |___    | |__| | | | | | | |__ | |__ | |__  | | \\ \\  |_   _|          ";
     cout<<"\n\t|______| |_| |_| |_| |_| |_| |_____|   |______| |_| |_| |____||____||____| |_|  \\ \\   |_|            ";
                   
    cout << "\n\t\t\t\t\t     ======================================\n";
   	cout<<"\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout<<"\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +";
    cout<<"\n\t\t\t  +      +                                              +      +";
    cout<<"\n\t\t\t  +      +               WELCOME TO                     +      +";
    cout<<"\n\t\t\t  +      + WORLD OF GAMES BY MANAHIL IFFAT  AND AINA    +      +";
    cout<<"\n\t\t\t  +      +                                              +      +";
    cout<<"\n\t\t\t  +      +                                              +      +";
    cout<<"\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +";
    cout<<"\n\t\t\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
   
    cout<<"\n\n\t\t\t\t MENU\n\t\t\t\t _______________________________________________|";
    cout<<"\n\t\t\t\t| [1] SUDOKU                                    |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [2] CARD GAME                                 |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [3] TicTacToe                                 |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [4] Word Chain                                |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [5] Word Puzzle                               |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [6] Guessing Game                             |";
    cout<<"\n\t\t\t\t|_______________________________________________|";
    cout<<"\n\t\t\t\t| [7] Exit                                      |";
	cout<<"\n\t\t\t\t|_______________________________________________|\t\t\t\t\t\t\t\t";
	cout<<"=========================================================================================="<<endl;
    char ch;
	do{
      cout<<"\n\t\t\t\tPlease select your desired operation: ";
      cin>>ch;
    }while(ch<='0' || ch>'7');
    
    if(ch=='1'){
    		Sudoku s;
            system("color 70");
            system("cls");

            int initial_board[n][n] = {
                {3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}
            };

            int board[n][n];

            int choice;
            do {
                cout << endl << endl;
                cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;
                cout << "\t\t\t|                        WELCOME TO SUDOKU Game!                                 |" << endl;
                cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;
                cout << "\t\t[1] Solve the Sudoku" << endl;
                cout << "\t\t[2] Unable to solve? View the solved Sudoku" << endl;
                cout << "\t\tEnter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        // Reset the board to the initial state before starting a new game
                        memcpy(board, initial_board, sizeof(board));
                        s.playGame(board);
                        break;
                    case 2:
                        if (s.solveSudoku(board, 0, 0)) {
                        	int newboard[n][n] = {
                                {3, 1, 6, 5, 7, 8, 4, 9, 2},
                                {5, 2, 9, 1, 3, 4, 7, 6, 8},
                                {4, 8, 7, 6, 2, 9, 5, 3, 1},
                                {2, 6, 3, 4, 1, 5, 9, 8, 9},
                                {9, 7, 4, 8, 6, 3, 1, 2, 5},
                                {8, 5, 1, 7, 9, 2, 6, 4, 3},
                                {1, 3, 8, 9, 4, 7, 2, 5, 6},
                                {6, 9, 2, 3, 5, 1, 8, 7, 4},
                                {7, 4, 5, 2, 8, 6, 3, 1, 9}
							};
                            cout << "Completely Solved Sudoku is: " << endl;
                            cout << endl << endl;
                            for (int row = 0; row < n; row++) {
                                for (int col = 0; col < n; col++) {
                                    if (col == 3 || col == 6)
                                        cout << " | ";
                                    cout <<newboard[row][col]<< " ";
                                }
                                if (row == 2 || row == 5) {
                                    cout << endl;
                                    for (int i = 0; i < n; i++)
                                        cout << "---";
                                }
                                cout << endl;
                            }
                            cout << endl;
                            cout << "Better luck next time!!!" << endl;
                        } else
                            cout << "No solution found" << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
            } while (choice == 1 || choice == 2);
	}
		
    else if(ch=='2'){
    	system("color 70");
    	system("cls");
        MemoryGameFinal Game;
        Game.start();
	}
	
	else if(ch=='3'){
		char ans;
		do{
		system("cls");
		system("color 70");
		int mode;
        cout << "1. Computer vs Player. " << endl;
        cout << "2. Player vs Player.   " << endl;
        cout << "Select game mode " << endl;
        cin >> mode;
        switch (mode) {
    	    TicTacToe t;
            case 1:
                t.computer_vs_player();
                break;
            case 2:
                t.player_vs_player();
                break;
            default:
                cout << "Please select a valid mode: " << endl;
            break;
        }
        cout<<"Do you want to play again? y/n?";
        cin>>ans;
    }while(ans=='y');
    system("cls");
	}
	else if(ch=='4'){
		system("cls");
		system("color 70");
	string word;
	char ch,ch1;
	Game g;
	cout<<"\n\t\t=====================================================";
	cout<<"\n\t\t************WELCOME TO WORD CHAIN GAME***************";
	cout<<"\n\t\t=====================================================";
	char ans;
	do{
    do{
	cout<<"\n\n\t\t1: Instructions\n\t\t2:Start Game\n\t\t";
	cin>>ch1;
	system("cls");
	if(ch1=='1'){
	g.instructions();
    }
    else if(ch1=='2'){
    g.start();
}
          else{
          	cout<<"\n\t\tInvalid input\n\t\tTry again";
          	sleep(1);
          	system("cls");
		  }
	}while(ch1!='1'&&ch1!='2');
	cout<<"\n\n\t\tDo you want to play again? y/n";
	cin>>ans;
    }while(ans=='y'||ans=='Y');
    system("cls");
	}
	else if(ch=='5'){
		system("color 70");
		 WordPuzzle game;
    game.playGame();
    game.displayScores();
	}
	else if(ch=='6'){
		system("cls");
		cout << "********************WELCOME TO GUESSING GAME*****************" << endl;
    cout << "Let's start the game: Press any key to start: ";
    getchar();
    system("cls");

    BinaryTree guessingGame;
	}
	else if(ch=='7'){
		exit(1);
	}
	else{
		continue;
	}
	cout<<"\n\n\t\tDo you want to go back ?y/n";
	cin>>x;
    system("cls");
}while(x=='y'||x=='Y');
}
