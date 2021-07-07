#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
char v1, v2, v3;
vector<vector<int>> adj;

void preorder(int start)
{
    cout << (char)(start + 'A');
    if (adj[start][0] != '.' - 'A') {
        preorder(adj[start][0]);
    }
    if (adj[start][1] != '.' - 'A') {
        preorder(adj[start][1]);
    }
}

void inorder(int start)
{
    if (adj[start][0] != '.' - 'A') {
        inorder(adj[start][0]);
    }
    cout << (char)(start + 'A');
    if (adj[start][1] != '.' - 'A') {
        inorder(adj[start][1]);
    }
}

void postorder(int start)
{
    if (adj[start][0] != '.' - 'A') {
        postorder(adj[start][0]);
    }
    if (adj[start][1] != '.' - 'A') {
        postorder(adj[start][1]);
    }
    cout << (char)(start + 'A');
}

int main()
{
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1 >> v2 >> v3;
        adj[v1 - 'A'].push_back(v2 - 'A');
        adj[v1 - 'A'].push_back(v3 - 'A');
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}