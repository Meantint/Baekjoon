#include <iostream>
#include <vector>

using namespace std;

int n;
char c1, c2, c3;

struct Node {
    char val;

    Node* left;
    Node* right;

    Node(char ch1, char ch2, char ch3)
    {
        val = ch1;
        if (ch2 == '.') {
            left = NULL;
        }
        else {
            left = new Node(ch2, '.', '.');
        }
        if (ch3 == '.') {
            right = NULL;
        }
        else {
            right = new Node(ch3, '.', '.');
        }
    }
    void find()
    {
        if (this->val == c1) {
            if (c2 != '.') {
                this->left = new Node(c2, '.', '.');
            }
            if (c3 != '.') {
                this->right = new Node(c3, '.', '.');
            }

            return;
        }
        if (this->left != NULL) {
            this->left->find();
        }
        if (this->right != NULL) {
            this->right->find();
        }

        return;
    }
    void preorder()
    {
        cout << this->val;
        if (this->left != NULL) {
            this->left->preorder();
        }
        if (this->right != NULL) {
            this->right->preorder();
        }
    }
    void inorder()
    {
        if (this->left != NULL) {
            this->left->inorder();
        }
        cout << this->val;
        if (this->right != NULL) {
            this->right->inorder();
        }
    }
    void postorder()
    {
        if (this->left != NULL) {
            this->left->postorder();
        }
        if (this->right != NULL) {
            this->right->postorder();
        }
        cout << this->val;
    }
};

int main()
{
    cin >> n;
    cin >> c1 >> c2 >> c3;
    Node* root = new Node(c1, c2, c3);
    while (--n) {
        cin >> c1 >> c2 >> c3;
        root->find();
    }
    root->preorder();
    cout << '\n';
    root->inorder();
    cout << '\n';
    root->postorder();
    cout << '\n';

    return 0;
}