#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
int answer = 0;
vector<bool> alpha(26, false);
vector<string> str_list;

void dfs(int count, int start_pos)
{
    // cout << count << ", " << start_pos << '\n';
    if (count == k) {
        // for (int i = 0; i < 26; ++i) {
        //     if (alpha[i]) {
        //         cout << (char)(i + 'a');
        //     }
        // }
        // cout << '\n';
        int ret = 0;

        int size = str_list.size();
        for (int i = 0; i < size; ++i) {
            bool isPos = true;
            int str_size = str_list[i].size() - 4;
            for (int j = 4; j < str_size; ++j) {
                if (!alpha[str_list[i][j] - 'a']) {
                    isPos = false;
                    break;
                }
            }

            if (isPos) {
                // cout << "wow\n";
                ++ret;
            }
        }

        if (answer < ret) {
            answer = ret;
        }

        return;
    }
    for (int i = start_pos; i < 26; ++i) {
        if (!alpha[i]) {
            alpha[i] = true;
            dfs(count + 1, i + 1);
            alpha[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;

    k -= 5;  // a, c, i, n, t
    if (k < 0) {
        cout << 0 << '\n';

        return 0;
    }
    else {
        alpha['a' - 'a'] = true;
        alpha['c' - 'a'] = true;
        alpha['i' - 'a'] = true;
        alpha['n' - 'a'] = true;
        alpha['t' - 'a'] = true;
    }

    str_list.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str_list[i];
    }

    dfs(0, 0);

    cout << answer << '\n';

    return 0;
}