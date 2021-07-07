#include <iostream>
#include <vector>

using namespace std;

int t;

struct Node {
    int val;

    Node* left;
    Node* right;

    Node(int num) : val(num)
    {
        left = NULL;
        right = NULL;
    }

    void push()
    {
        if (t < this->val) {
            if (this->left == NULL) {
                this->left = new Node(t);

                return;
            }
            this->left->push();
        }
        else {
            if (this->right == NULL) {
                this->right = new Node(t);

                return;
            }
            this->right->push();
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
        cout << this->val << '\n';
    }
};

int main()
{
    Node* root = NULL;
    while (cin >> t) {
        if (root == NULL) {
            root = new Node(t);
        }
        else {
            root->push();
        }
    }
    root->postorder();
    cout << '\n';

    return 0;
}