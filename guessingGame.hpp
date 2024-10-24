#include<iostream>

using namespace std;

class BTNode {
public:
    BTNode* left;
    BTNode* right;
    string data;

    BTNode(string val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
	bool gameFinished;
    BTNode* root;

public:
    BinaryTree() {
    	gameFinished = false;
        root = new BTNode("Can it fly? ");
        root->left = new BTNode("Is your object living? ");
        root->right = new BTNode("bird? ");
        root->left->left = new BTNode("Door? ");
        root->left->right = new BTNode("Human? ");
        begin(root);
    }


          bool isValidYNInput(const char& ch) {
        return (ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n');
    }
    char getValidYNInput() {
        char input;
        bool validInput = false;
        while (!validInput) {
            cout << "Enter Y or N: ";
            cin >> input;
            validInput = isValidYNInput(input);
            if (!validInput) {
                cout << "Invalid input! Please enter Y or N." << endl;
            }
        }
        return input;
    }        
             
    void begin(BTNode* tree) {
    	if (!gameFinished && tree != NULL) { 
        if (tree != NULL) {
            char ch;
            cout << tree->data;
            ch = getValidYNInput(); 
            if (ch == 'Y' || ch == 'y') {
                if (tree->right != NULL) {
                    begin(tree->right);
                } else {
                    win();
                }
            } else {
                if (tree->left != NULL) {
                    begin(tree->left);
                } else {
                    lose(tree);
                }
            }
        }
    }
    }

    void win() {
        char ch;
        cout << "I win! Do you want to play again? ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            begin(root);
        } else {
            cout << "THANK YOU FOR PLAYING! ";
            gameFinished = true;
        }
    }

  void lose(BTNode* tree) {
        string answer, question, answer1, answer2;
        char ans;
        cout << "Then what is it? ";
        fflush(stdin);
        getline(cin,answer);

        cout << "Please enter a question to distinguish " << tree->data << " from " << answer << ": ";
                getline(cin,question);
        cout << "What would be the answer for " << answer << " if the question is " << question << "? ";
        ans = getValidYNInput(); // Use the validated Y/N input method

        BTNode* newQuestion = new BTNode(question);
        BTNode* newAnswer = new BTNode(answer);

        if (ans == 'Y' || ans == 'y') {
            tree->left = newQuestion;
            tree->left->right = newAnswer;
            cout << "What will it be if it is no? ";
            getline(cin,answer1);
            BTNode* newanswer1 = new BTNode(answer1);
            tree->left->left = newanswer1;
        } else {
            tree->left = newQuestion;
            tree->left->left = newAnswer;
            cout << "What will it be if it is yes? ";
            fflush(stdin);
            getline(cin,answer2);
            BTNode* newanswer2 = new BTNode(answer2);
            tree->left->right = newanswer2;
        }

        cout << endl << "Starting again: " << endl;
        begin(root);
    
}

         ~BinaryTree() {
        destroyTree(root);
    }
    
    
    void destroyTree(BTNode* tree) {
        if (tree != NULL) {
            destroyTree(tree->left);
            destroyTree(tree->right);
            delete tree;
        }
    }
    

};

