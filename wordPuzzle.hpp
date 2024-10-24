#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
using namespace std;

struct Puzzle {
    char matrix[10][10];
    string word;
};

struct Player {
    string name;
    int score;
};

class WordPuzzle {
private:
    vector<string> words;
    vector<Player> players;
    stack<int> scoresStack;

    void generateMatrix(Puzzle& puzzle) {
        int r;
        char c;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                r = rand() % 26;
                c = 'a' + r;
                puzzle.matrix[i][j] = c;
            }
        }
    }
void placeWord(Puzzle& puzzle) {
    int row = rand() % 10;
    int column = rand() % 10;

    if (puzzle.word.length() % 2 == 0) {
        // horizontally
        while (column + puzzle.word.length() > 10) {
            column = rand() % 10;
        }

        for (int i = 0; i < puzzle.word.length(); i++, column++) {
            puzzle.matrix[row][column] = puzzle.word[i];
        }
    } else {
        // vertically
        while (row + puzzle.word.length() > 10) {
            row = rand() % 10;
        }

        for (int i = 0; i < puzzle.word.length(); i++, row++) {
            puzzle.matrix[row][column] = puzzle.word[i];
        }
    }
}


public:
   WordPuzzle() {
    words.push_back("apple");
    words.push_back("banana");
    words.push_back("date");
    words.push_back("cherry");
    words.push_back("pear");
    words.push_back("mango");
    words.push_back("pineapple");
    words.push_back("avocado");
    words.push_back("grapes");
    words.push_back("strawberry");
}




    void playGame() {
        char input;
            system("cls");
            displayWelcome();

            Player currentPlayer;
            cout << "Enter your name: ";
            cin >> currentPlayer.name;
                    do {
                    	system("cls");
            currentPlayer.score = 0;

            Puzzle puzzle;
            generateMatrix(puzzle);

            int index = rand() % words.size();
            puzzle.word = words[index];

            placeWord(puzzle);

            displayPuzzle(puzzle);

            cout << "Press 1 for direct guess input\n";
            cout << "Press 2 for hint-based guess input\n";

            int hint;
            cin >> hint;

            string guess;
            if (hint == 1) {
                cout << "Enter guessing word: ";
                cin >> guess;
            } else if (hint == 2) {
                cout << "The guessing word size is: " << puzzle.word.length() << endl;
                cout<<endl;
                cout<<"The hint is that, it's a fruit name: "<<endl;
                cout << "Enter guessing word: ";
                cin >> guess;
            } else {
                cout << "Invalid input. Please try again.\n";
                continue;
            }

            if (puzzle.word == guess) {
                cout << "Congratulations! You guessed the right word in the puzzle\n";
                currentPlayer.score = 1;
            } else {
                cout << "Sorry, you guessed the wrong word\n";
            }

            players.push_back(currentPlayer);
            scoresStack.push(currentPlayer.score);

            cout << "Would you like to play again? (y/n): ";
            cin >> input;

        } while (input == 'y'||input=='Y');
    }

    void displayWelcome() {
        cout << "\t\t\tWORD SEARCHING PUZZLE GAME\n";
        cout << "Welcome\n";
        cout << "A puzzle of alphabet words is shown on screen. You have to guess a hidden correct word from the puzzle.\n";
        cout << "For each correct word, you will get one score\n\n";
    }

    void displayPuzzle(const Puzzle& puzzle) {
    cout << "Puzzle\n\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << puzzle.matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

     void displayScores() {
        cout << "Scoreboard:\n";
        while (!scoresStack.empty()) {
            cout << "Score: " << scoresStack.top() << endl;
            scoresStack.pop();
        }
    }
};
