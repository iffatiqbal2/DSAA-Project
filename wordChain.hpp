#include<iostream>
#include<fstream>
using namespace std;

class ClassNode {
public:
    int value;
    bool reveal;
    ClassNode* next;
    string data;
    ClassNode* left;
    ClassNode* right;

    ClassNode(string d) {
        data = d;
        next = NULL;
        left = NULL;
        right = NULL;
    }

    ClassNode(int val) : value(val), reveal(false), next(NULL) {}
};

class Game {
private:
    ClassNode* head;

public:
    Game() {
        head = NULL;
    }
    void insertNode(string data) {
        ClassNode* newnode = new ClassNode(data);
        if (head == NULL) {
            head = newnode;
        } else {
            ClassNode* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
    bool checkword(string data) {
        if (head == NULL) {
            return true;
        } else {
            ClassNode* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            string word = ptr->data;
            if (word[word.size() - 1] == data[0]) {
                return true;
            } else
                return false;
        }
    }
    bool checkRepitition(string data) {
        if (head == NULL) {
            return true;
        } else {
            ClassNode* ptr = head;
            while (ptr != NULL) {
                if (ptr->data != data) {
                    ptr = ptr->next;
                } else if (ptr->data == data) {
                    return false;
                }
            }
            return true;
        }
    }
    bool checkwordfromfile(string data) {
        ifstream file("cities.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line == data) {
                    file.close();
                    return true;
                }
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
        return false;
    }

    void deleteWordFromFile(const std::string& wordToDelete) {
        ifstream inputFile("cities.txt");
        ofstream tempFile("temp.txt");

        if (!inputFile.is_open() || !tempFile.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(inputFile, line)) {
            if (line != wordToDelete) {
                tempFile << line << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        remove("cities.txt");

        rename("temp.txt", "cities.txt");
    }

    string searchwordfromfile() {
        if (head == NULL) {
            cout << "The list is empty!" << endl;
            return "";
        }

        ClassNode* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        string lastword = ptr->data;
        ifstream file("cities.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line[0] == lastword[lastword.size() - 1]) {
                    file.close();
                    return line;
                }
            }
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
        return "You Win \n\t\t\tComputer Loose";
    }

    void printList() {
        ClassNode* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << "--";
            ptr = ptr->next;
        }
    }
    void instructions() {
        Game g;
        char ch;
        cout << "\n\t\tInstructions\n\t1: The game will be between computer and player.\n\t2: You have to write a country name or continent or ocean name that starts with the last letter of the previous word.\n\t3: The game ends when no valid words can be formed based on the last letters of the existing words.\n\t4: The game ends if a word is repeated in the chain.";
        cout << "\n\t\t=====================================================";
        cout << "\n\n\t\tEnter any key to start the game: ";
        cin >> ch;
        g.start();
    }
    int start() {
        string word;
        Game g;
        system("cls");
        int flag = 1;
        cout << "\n\t\tFirst Alphabet is a: ";
        while (flag) {
            fflush(stdin);
            cout << "\n\n\t\tEnter  COUNTRY or CONTINENT or OCEAN name : ";
            cin >> word;
            system("cls");
            if (g.checkword(word) && g.checkRepitition(word) && g.checkwordfromfile(word)) {
                g.insertNode(word);
                g.printList();
                g.deleteWordFromFile(word);
            } else {
                cout << "\n\t\t\t Computer Wins\n\t\t\t YOU LOOSE\n\t\t\tGAME OVER";
                return -1;
                flag = 0;
            }

            string computerword;
            cout << endl << "Computer's Turn: ";
            fflush(stdin);
            computerword = g.searchwordfromfile();
            if (g.checkRepitition(computerword)) {
                g.insertNode(computerword);
                g.printList();
                g.deleteWordFromFile(computerword); // Added line to delete the computer-generated word
            }
        }
        return 0;
    }
};
