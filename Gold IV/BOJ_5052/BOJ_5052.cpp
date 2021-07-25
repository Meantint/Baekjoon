#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 10

using namespace std;

int tc;

struct Trie {
    Trie* node[MAX_SIZE];

    bool terminal;
    bool exist_child;
    Trie()
    {
        terminal = false;
        exist_child = false;
        fill(node, node + MAX_SIZE, nullptr);
    }
    ~Trie()
    {
        for (int i = 0; i < MAX_SIZE; ++i) {
            if (node[i]) {
                delete (node[i]);
            }
        }
    }

    void insert(const char* key)
    {
        if (*key == '\0') {
            terminal = true;
        }
        else {
            exist_child = true;
            int next = *key - '0';

            if (!node[next]) {
                node[next] = new Trie;
            }
            node[next]->insert(key + 1);
        }
    }

    bool exist_prefix()
    {
        if (exist_child && terminal) {
            return true;
        }

        for (int next = 0; next < MAX_SIZE; ++next) {
            if (node[next] && node[next]->exist_prefix()) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    cin >> tc;
    while (tc--) {
        Trie* root = new Trie;

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            char temp[20];
            cin >> temp;

            root->insert(temp);
        }

        if (root->exist_prefix()) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}