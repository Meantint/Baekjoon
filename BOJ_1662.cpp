#include <iostream>
#include <string>

using namespace std;

string str;
int curPos = 0;
int strSize;

int dfs(int idx)
{
    int result = 0;
    for (int i = idx; i < strSize; ++i) {
        if (str[i] == '(') {
            int cnt = str[i - 1] - '0';
            result += cnt * dfs(i + 1);
            i = curPos;
        }
        else if (str[i] == ')') {
            curPos = i;
            break;
        }
        else {
            if (i + 1 < strSize) {
                if (str[i + 1] == '(') {
                    continue;
                }
                else {
                    ++result;
                }
            }
            else {
                ++result;
            }
        }
    }
    return result;
}

int main()
{
    cin >> str;
    strSize = str.size();

    cout << dfs(0) << '\n';

    return 0;
}