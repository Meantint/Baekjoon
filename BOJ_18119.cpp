#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
int base = 0;
string str;
vector<int> words;
vector<string> real;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 26; ++i) {
        base |= (1 << i);
    }
    cin >> n >> m;
    words = vector<int>(n, 0);
    real = vector<string>(n, "");
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int size = str.size();
        for (int j = 0; j < size; ++j) {
            words[i] = (words[i] | (1 << (25 - (str[j] - 'a'))));
        }
        real[i] = str;
    }
    for (int i = 0; i < m; ++i) {
        int num;
        char word;
        cin >> num >> word;

        // 까먹게 됨
        if (num == 1) {
            base -= pow(2, 25 - (word - 'a'));
        }
        else {
            base += pow(2, 25 - (word - 'a'));
        }
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((words[j] & base) == words[j]) {
                // cout << "isPos when words[j] : " << real[j] << ", base : " << base << ", words[j] & base : " << (words[j] & base) << '\n';
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}