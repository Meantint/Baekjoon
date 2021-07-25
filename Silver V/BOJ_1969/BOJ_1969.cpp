#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> info;
string answer;

int main()
{
    cin >> n >> m;

    info.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    for (int k = 0; k < m; ++k) {
        vector<int> alpha(26, 0);
        for (int i = 0; i < n; ++i) {
            ++alpha[info[i][k] - 'A'];
        }

        int max_index = -1;
        int max_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (max_count < alpha[i]) {
                max_count = alpha[i];
                max_index = i;
            }
        }

        answer += ('A' + max_index);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            if (answer[k] != info[i][k]) {
                ++ret;
            }
        }
    }

    cout << answer << '\n'
         << ret << '\n';

    return 0;
}