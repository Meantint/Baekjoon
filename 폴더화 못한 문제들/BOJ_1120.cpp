#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int main()
{
    cin >> str1 >> str2;

    int size1 = str1.size();
    int size2 = str2.size();
    int minCount = INT_MAX;
    for (int i = 0; i < size2 - size1 + 1; ++i) {
        int cnt = 0;
        for (int j = 0; j < size1; ++j) {
            if (str1[j] != str2[j + i]) {
                ++cnt;
            }
        }
        minCount = min(minCount, cnt);
    }
    cout << minCount << '\n';

    return 0;
}