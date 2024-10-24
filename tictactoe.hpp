#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;



class ticNode{
	public:
		char data;
    ticNode* next;

    ticNode(char value) : data(value), next(NULL) {}
		
};
class LinkedList {
public:
    ticNode* head;

    LinkedList() : head(NULL) {}

    void append(char value) {
        ticNode* newNode = new ticNode(value);
        if (!head) {
            head = newNode;
        } else {
            ticNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

class TicTacToe {
public:
    void show_board(LinkedList* rows[3]) {
        for (int i = 0; i < 3; ++i) {
            cout << "     |     |     \n";
            ticNode* current = rows[i]->head;
            for (int j = 0; j < 3; ++j) {
                cout << "  " << current->data;
                if (j < 2) {
                    cout << "  |";
                } else {
                    cout << "  \n";
                }
                current = current->next;
            }

            if (i < 2) {
                cout << "_____|_____|_____\n";
            } else {
                cout << "     |     |     \n";
            }
        }
    }

    void get_computer_choice(LinkedList* rows[3]) {
        srand(time(0));
        int choice;
        do {
            choice = rand() % 9;
        } while (get_node(rows, choice / 3, choice % 3)->data != ' ');
        get_node(rows, choice / 3, choice % 3)->data = '0';
    }

  void get_x_player_choice(LinkedList* rows[3]) {
    while (true) {
        int choice;
        cout << "Select your position (1-9): " << endl;

        if (cin >> choice) {
            choice--;  // Adjust choice to be zero-based

            if (choice >= 0 && choice <= 8 && get_node(rows, choice / 3, choice % 3)->data == ' ') {
                get_node(rows, choice / 3, choice % 3)->data = 'X';
                return;
            } else {
                cout << "Invalid choice. Please select an empty position." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;

            // Clear the input buffer and ignore any remaining characters
            cin.clear();
            cin.ignore();
        }
    }
}

    void get_0_player_choice(LinkedList* rows[3]) {
         while (true) {
        int choice;
        cout << "Select your position (1-9): " << endl;

        if (cin >> choice) {
            choice--;  // Adjust choice to be zero-based

            if (choice >= 0 && choice <= 8 && get_node(rows, choice / 3, choice % 3)->data == ' ') {
                get_node(rows, choice / 3, choice % 3)->data = '0';
                return;
            } else {
                cout << "Invalid choice. Please select an empty position." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;

            // Clear the input buffer and ignore any remaining characters
            cin.clear();
            cin.ignore();
        }
    }
    }

    int count_board(char symbol, LinkedList* rows[3]) {
        int total = 0;
        for (int i = 0; i < 3; i++) {
            ticNode* current = rows[i]->head;
            for (int j = 0; j < 3; j++) {
                if (current->data == symbol) {
                    total++;
                }
                current = current->next;
            }
        }
        return total;
    }

    char check_winner(LinkedList* rows[3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            ticNode* current = rows[i]->head;
            if (current->data == current->next->data && current->data == get_node(rows, i, 2)->data) {
                return current->data;
            }
        }

        for (i = 0; i < 3; i++) {
            if (get_node(rows, 0, i)->data == get_node(rows, 1, i)->data && get_node(rows, 0, i)->data == get_node(rows, 2, i)->data) {
                return get_node(rows, 0, i)->data;
            }
        }

        if (get_node(rows, 0, 0)->data == get_node(rows, 1, 1)->data && get_node(rows, 1, 1)->data == get_node(rows, 2, 2)->data) {
            return get_node(rows, 0, 0)->data;
        }

        if (get_node(rows, 0, 2)->data == get_node(rows, 1, 1)->data && get_node(rows, 1, 1)->data == get_node(rows, 2, 0)->data) {
            return get_node(rows, 0, 2)->data;
        }

        for (i = 0; i < 3; i++) {
            ticNode* current = rows[i]->head;
            for (j = 0; j < 3; j++) {
                if (current->data != 'X' && current->data != '0') {
                    return ' ';
                }
                current = current->next;
            }
        }

        return 'D';
    }

    void player_vs_player() {
        string x_player_name, o_player_name;
        cout << "Enter X player name: " << endl;
        cin >> x_player_name;
        cout << "Enter 0 player name: " << endl;
        cin >> o_player_name;

        LinkedList* rows[3];
        for (int i = 0; i < 3; ++i) {
            rows[i] = new LinkedList();
            for (int j = 0; j < 3; ++j) {
                rows[i]->append(' ');
            }
        }

        while (true) {
            system("cls");
            show_board(rows);
            if (count_board('X', rows) == count_board('0', rows)) {
                cout << x_player_name << "'s Turn: " << endl;
                get_x_player_choice(rows);
            } else {
                cout << o_player_name << "'s Turn: " << endl;
                get_0_player_choice(rows);
            }
            char winner = check_winner(rows);
            if (winner == 'X') {
                system("cls");
                show_board(rows);
                cout << x_player_name << " WON THE GAME: " << endl;
                break;
            } else if (winner == '0') {
                system("cls");
                show_board(rows);
                cout << o_player_name << " WON THE GAME: " << endl;
                break;
            } else if (winner == 'D') {
                cout << "Game is DRAW: " << endl;
                break;
            }
        }

        // Cleanup
        for (int i = 0; i < 3; ++i) {
            delete rows[i];
        }
    }

    void computer_vs_player() {
        string player_name;
        cout << "Enter your name: " << endl;
        cin >> player_name;

        LinkedList* rows[3];
        for (int i = 0; i < 3; ++i) {
            rows[i] = new LinkedList();
            for (int j = 0; j < 3; ++j) {
                rows[i]->append(' ');
            }
        }

        while (true) {
            system("cls");
            show_board(rows);
            if (count_board('X', rows) == count_board('0', rows)) {
                cout << player_name << "'s Turn: " << endl;
                get_x_player_choice(rows);
            } else {
                get_computer_choice(rows);
            }
            char winner = check_winner(rows);
            if (winner == 'X') {
                system("cls");
                show_board(rows);
                cout << player_name << " Won the game: " << endl;
                break;
            } else if (winner == '0') {
                system("cls");
                show_board(rows);
                cout << "  Computer Won the game: " << endl;
                break;
            } else if (winner == 'D') {
                cout << "Game is DRAW: " << endl;
            }
        }

        // Cleanup
        for (int i = 0; i < 3; ++i) {
            delete rows[i];
        }
    }

    ticNode* get_node(LinkedList* rows[3], int row, int col) {
        ticNode* current = rows[row]->head;
        for (int i = 0; i < col; ++i) {
            current = current->next;
        }
        return current;
    }
};
