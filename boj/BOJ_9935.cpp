// 굳이 중복해서 계산해서 시간 초과가 계속남.
// 기존의 str1의 값을 갱신하면서 풀면 안됨!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string isBomb(string str1, string str2)
{
    string ans = "";
    int size = str1.size();
    int comp = str2.size();
    char lastCh = str2.back();
    for (int i = 0; i < size; ++i) {
        ans += str1[i];
        if (str1[i] == lastCh) {
            if (ans.size() >= comp && ans.substr(ans.size() - comp, comp) == str2) {
                // ans = ans.substr(0, ans.size() - comp + 1);
                for (int j = 0; j < comp; ++j) {
                    ans.pop_back();
                }
            }
        }
    }

    return ans;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    string answer = isBomb(str1, str2);
    if (answer.empty()) {
        cout << "FRULA" << '\n';
    }
    else {
        cout << answer << '\n';
    }
    return 0;
}