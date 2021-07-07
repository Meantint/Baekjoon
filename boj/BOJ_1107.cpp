#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int minNum = 2112345678;
vector<bool> btn(10, true);

void brute(string num)
{
    for (int i = 0; i < 10; ++i) {
        if (btn[i]) {
            string tmp = num + to_string(i);
            minNum = min(minNum, abs(n - stoi(tmp)) + (int)tmp.size());

            if (tmp.size() < 6) {
                brute(tmp);
            }
        }
    }
}

int main()
{
    cin >> n;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        int b;
        cin >> b;
        btn[b] = false;
    }
    minNum = min(minNum, abs(100 - n));

    brute("");
    cout << minNum << '\n';

    return 0;
}