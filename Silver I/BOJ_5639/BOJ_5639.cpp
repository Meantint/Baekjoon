#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

typedef struct node {
    int key;
    node *left;
    node *right;

    node()
    {
        left = right = NULL;
    }
} node;

node *SetPos(node *root, int target)
{
    if (root == NULL) {
        root = new node;
        root->key = target;
    }
    else {
        if (root->key < target) {  // 더 큰 경우 right
            root->right = SetPos(root->right, target);
        }
        else {  // 더 작은 경우 left
            root->left = SetPos(root->left, target);
        }
    }
    return root;
}

void PostOrder(node *root)
{
    if (root == NULL) {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->key << '\n';
}

int main()
{
    node *root = NULL;

    while (getline(cin, str)) {
        int cur = stoi(str);
        root = SetPos(root, cur);
    }
    PostOrder(root);

    return 0;
}