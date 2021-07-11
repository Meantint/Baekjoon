#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 0;
int ansSize = 0;
int tSize = 0;

int main()
{
    cin >> n;

    string str;
    cin >> str;

    ansSize = str.size();
    vector<int> ans(26, 0);
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        ++ans[str[i] - 'A'];
    }
    for (int i = 1; i < n; ++i) {
        cin >> str;
        size = str.size();
        vector<int> t(26, 0);
        for (int j = 0; j < size; ++j) {
            ++t[str[j] - 'A'];
        }
        int sum = 0;
        for (int j = 0; j < 26; ++j) {
            sum += abs(ans[j] - t[j]);
        }
        if (ansSize == size) {
            if (sum <= 2) {
                ++answer;
            }
        }
        else {
            if (sum <= 1) {
                ++answer;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}