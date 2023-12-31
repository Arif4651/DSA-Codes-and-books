#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int woc;
    Node *children[26];
    Node() {
        woc = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node *root, string s) {
    Node *current = root;
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'A';
        if (current->children[index] == NULL) {
            current->children[index] = new Node();
        }
        current = current->children[index];
    }
    current->woc++;
}

int trie_search(Node *root, string s) {
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'A';
        if (temp->children[index] == NULL) {
            return 0;
        }
        temp = temp->children[index];
    }
    return temp->woc;
}

void printTRIE(Node *root, string s = "") {
    if (root == NULL) {
        return;
    }
    if (root->woc > 0) {
        cout << s <<" "<<root->woc<< endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char c = char(i + 'A');
            printTRIE(root->children[i], s + c);
        }
    }
}

bool isLeaf(Node *u) {
    for (int i = 0; i < 26; i++) {
        if (u->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

Node* deletee(string x, Node *root, int k = 0) {
    if (root == NULL) {
        return NULL;
    }

    if (k == x.size()) {
        if (root->woc > 0) {
            root->woc--; ///if you want to delele the string all times together like if AB has 2 times and u want to delete 2 times together then--> root->woc=0
        }
        if (isLeaf(root) && root->woc == 0) {
            delete root;
            return NULL;
        }
        return root;
    }

    int index = x[k] - 'A';
    root->children[index] = deletee(x, root->children[index], k + 1);

    if (isLeaf(root) && root->woc == 0) {
        delete (root);
        return NULL;
    }
    return root;
}

int main() {
    Node *root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            cout << "Enter string to delete:" << endl;
            cin >> x;
            root = deletee(x, root);
            cout << x << " is deleted from the trie" << endl;
        } else if (choice == 4) {
            printTRIE(root);
        } else if (choice == 5) {
            printTRIE(root);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}

