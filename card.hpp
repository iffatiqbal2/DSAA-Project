#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Node {
public:
    int value;
    bool exposed;
    Node* next;

    Node(int val) : value(val), exposed(false), next(NULL) {}
};

// Class for a row of cards
class CardRow {
public:
    Node* head;

    CardRow() : head(NULL) {}

    // Function to add a card to the row
    void addCard(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete the entire row
    void deleteRow() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
    }
};

// Class for the Memory Game Board
class MemoryGameBoard {
private:
    CardRow* RowArray;
    int rowCount;
    int columnCount;
    int score;

public:
    MemoryGameBoard() : RowArray(NULL), rowCount(0), columnCount(0), score(0) {}

    void initialize(int rows, int columns) {
        rowCount = rows;
        columnCount = columns;
        score = 0;

        // Create rows
        RowArray = new CardRow[rows];
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                RowArray[row].addCard(rand() % 8 + 1);
            }
        }
    }

    // Function to display the game board
    void display() {
        cout << "    1 2 3 4" << endl;
        cout << "  ";
        for (int i = 0; i <= 8; i++) {
            cout << "-";
        }
        cout << endl;

        for (int row = 0; row < rowCount; row++) {
            cout << row + 1 << " | ";
            Node* current = RowArray[row].head;
            while (current) {
                if (current->exposed) {
                    cout << current->value;
                } else {
                    cout << '*';
                }
                cout << ' ';
                current = current->next;
            }
            cout << endl;
        }
        cout << endl;
    }

    // Function to check if the game is over
    bool isGameOver() {
        return score == rowCount * columnCount;
    }

    // Function to expose a card
    void exposeCard(int row, int column) {
        Node* current = RowArray[row].head;
        for (int i = 0; i < column; i++) {
            current = current->next;
        }
        current->exposed = true;
    }

    // Function to check if a card is exposed
    bool isCardExposed(int row, int column) {
        Node* current = RowArray[row].head;
        for (int i = 0; i < column; i++) {
            current = current->next;
        }
        return current->exposed;
    }

    // Function to get the value of a card
    int getCardValue(int row, int column) const {
        Node* current = RowArray[row].head;
        for (int i = 0; i < column; i++) {
            current = current->next;
        }
        return current->value;
    }

    // Function to cover a card
    void coverCard(int row, int column) {
        Node* current = RowArray[row].head;
        for (int i = 0; i < column; i++) {
            current = current->next;
        }
        current->exposed = false;
    }

    // Function to increase points
    void increasePoints() {
        score += 2;
    }

    // Destructor to clean up memory
    ~MemoryGameBoard() {
        for (int i = 0; i < rowCount; i++) {
            RowArray[i].deleteRow();
        }
        delete[] RowArray;
    }

    // Function to get points
    int getPoints() {
        return score;
    }
};

// Class for the Memory Game
class MemoryGameFinal {
private:
    MemoryGameBoard gameBoard;
    int row1Value, column1Value, row2Value, column2Value;
    int menu;
    bool again;

public:
    MemoryGameFinal() : again(true) {}
    void resetAndGoBackToMenu() {
        gameBoard.~MemoryGameBoard();  // Destructor to clean up memory
        again = false;
    }

    // Function to start the game
    void start() {
        cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;
        cout << "\t\t\t|                        WELCOME TO CARD GAME!                                 |" << endl;
        cout << "\t\t\t<++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>" << endl;

        while (again) {
            cout << "\t\tGame Menu" << endl;
            cout << "\t\t[1] NEW GAME" << endl;
            cout << "\t\t[2] EXIT" << endl;
            cout << "\t\t[3] GO BACK TO MAIN MENU?" << endl;
            cout << "\t\tInSTRUCTION **IF WANT TO QUICK THE CONTINUED GAME ENTER -1**" << endl;
            cout<<endl;
            cout << "\t\tEnter your choice: ";
            cin >> menu;

            if (menu == 1) {
                gameBoard.initialize(4, 4);
                display();
                Loop();
            } 
			else if (menu == 2) {
                cout << "PLAY AGAIN" << endl;
                cout << "Type '1' to play again and '0' to leave" << endl;
                cin >> again;
            }
			else if(menu==3){
            	resetAndGoBackToMenu();
            	return;
			}
			else{
				cout<<"PLS ENTER RIGHT OPTION"<<endl;
				continue;
			}
        }
    }

    // Function to play the game loop
    void Loop() {
        while (!gameBoard.isGameOver()) {
            getUserInput();
            exposeCards();
            display();
            Match();
        }

        cout << "CONGRATULATIONS GAME COMPLETED" << "!" << endl << endl;
    }
    
    void clearInputBuffer() {
    // Function to manually clear the input buffer until a newline character is encountered
        while (cin.get() != '\n'){}
	}
	
    // Function to get user input
    void getUserInput() {
        do {
            cout << "\nEnter Row of 1st Card: ";
            cin >> row1Value;

            if (cin.fail() || row1Value < 1 || row1Value >=5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear();  // Clear the error state
                clearInputBuffer();  // Manually clear the input buffer
			}
        } while (row1Value < 1 || row1Value >=5);

        do {
            cout << "Enter Column of 1st Card: ";
            cin >> column1Value;
            if (cin.fail() || column1Value < 1 || column1Value >=5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear();
                clearInputBuffer();
			}
        } while (column1Value < 1 || column1Value >=5);
        
        do {
        	cout<<endl;
            cout << "Enter Row of 2nd Card: ";
            cin >> row2Value;
            if (cin.fail() || row2Value < 1 || row2Value >= 5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear();
                clearInputBuffer();
			}
        } while (row2Value < 1 || row2Value >=5);
        
        do {
            cout << "Enter Column of 2st Card: ";
            cin >>column2Value;
            if (cin.fail() || column2Value< 1 || column2Value>=5) {
                cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                cin.clear();
                clearInputBuffer();
			}
        } while (column2Value < 1 || column2Value >=5);
        
    
        if (row1Value==column1Value && row2Value==column2Value && row1Value==row2Value) {
        	system("cls");
            start();
		}

        row1Value--;
        column1Value--;
        row2Value--;
        column2Value--;
    }

    // Function to expose cards
    void exposeCards() {
        gameBoard.exposeCard(row1Value, column1Value);
        gameBoard.exposeCard(row2Value, column2Value);
    }

    // Function to display the game board
    void display() {
        system("cls");
        gameBoard.display();
    }

    // Function to match the cards
    void Match() {
        if (gameBoard.getCardValue(row1Value, column1Value) == gameBoard.getCardValue(row2Value, column2Value)) {
            gameBoard.increasePoints();
            cout << "CONGRATULATIONS! CARDS MATCH" << endl;
            cout << "Points: " << gameBoard.getPoints() << endl << endl;
        } else {
            cout << "YOU FAILED! CARDS DO NOT MATCH" << endl;
            cout << "Points: " << gameBoard.getPoints() << endl << endl;

            gameBoard.coverCard(row1Value, column1Value);
            gameBoard.coverCard(row2Value, column2Value);
        }
    }
};
