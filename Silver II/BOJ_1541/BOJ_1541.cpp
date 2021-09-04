#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> num;
vector<char> op;

int main()
{
    cin >> str;
    int size = str.size();
    int val = 0;
    for (int i = 0; i < size; ++i) {
        if ('0' <= str[i] && str[i] <= '9') {
            val *= 10;
            val += (str[i] - '0');
        }
        else {  // +, -
            num.push_back(val);
            val = 0;
            op.push_back(str[i]);
        }
    }
    num.push_back(val);  // 마지막 숫자 넣어주기

    vector<int> sv;  // sv[0] : 기준 숫자, sv[1...] : sv[0]에 빼줘야할 숫자
    sv.push_back(num[0]);
    int oSize = op.size();
    for (int i = 0; i < oSize; ++i) {
        if (op[i] == '+') {
            sv.back() += num[i + 1];
        }
        else {
            sv.push_back(num[i + 1]);
        }
    }
    int answer = sv[0];
    int svSize = sv.size();
    for (int i = 1; i < svSize; ++i) {
        answer -= sv[i];
    }
    cout << answer << '\n';

    return 0;
}