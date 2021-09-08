#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(string str)
{
    int size = str.size();
    vector<string> info;

    for (int i = 0; i < size; ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            info.push_back("");
            info.back() += str[i];
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            info.push_back("");
            info.back() += str[i];
        }
        else {  // 괄호 없애기 작업
            string temp = "";
            int depth = 1;
            for (int j = i + 1; j < size; ++j) {
                if (str[j] == '(') {
                    ++depth;
                }
                else if (str[j] == ')') {
                    --depth;
                }
                temp += str[j];

                if (depth == 0) {
                    temp.pop_back();
                    i = j;
                    break;
                }
            }

            string newTemp = solve(temp);

            info.push_back(newTemp);
        }
    }

    // *, / 우선 처리
    vector<string> newInfo;
    newInfo.push_back(info[0]);

    int iSize = info.size();
    for (int i = 1; i < iSize; i += 2) {
        if (info[i] == "*" || info[i] == "/") {
            newInfo.back() += info[i + 1];
            newInfo.back() += info[i];
        }
        else {
            newInfo.push_back(info[i]);
            newInfo.push_back(info[i + 1]);
        }
    }

    // +, - 처리
    string ret = newInfo[0];
    int nSize = newInfo.size();
    for (int i = 1; i < nSize; i += 2) {
        ret += newInfo[i + 1];
        ret += newInfo[i];
    }

    return ret;
}

int main()
{
    string str;
    cin >> str;

    cout << solve(str) << '\n';
}