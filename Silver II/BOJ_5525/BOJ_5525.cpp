#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, answer = 0;
string str;
vector<int> info;

int main()
{
    cin >> n >> m >> str;
    for (int i = 0; i < m; ++i) {
        int ret = 0;
        if (str[i] == 'I') {
            int temp = i + 1;
            while (temp < m && str.substr(temp, 2) == "OI") {
                ++ret;
                temp += 2;
            }
            info.push_back(ret);
            i = temp - 1;
        }
    }

    int iSize = info.size();
    for (int i = 0; i < iSize; ++i) {
        if (info[i] >= n) {
            answer += (info[i] - n + 1);
        }
    }
    cout << answer << '\n';

    return 0;
}