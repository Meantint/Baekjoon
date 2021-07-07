#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int num;
int st, ed;
bool isFel;
string s;

// 값들을 초기화 해주는 함수
void init()
{
    s = to_string(num);
    st = 0;
    ed = s.size() - 1;
    isFel = true;
}

int main()
{
    cin >> num;
    while (num != 0) {
        init();
        // st = ed인 경우는 어차피 같은 문자이므로 검사할 필요가 없다.
        while (st < ed) {
            if (s[st] == s[ed]) {
                ++st;
                --ed;
            }
            else {
                isFel = false;
                break;
            }
        }
        // while문 검사가 끝났을 때 isFel이 true라면 팰린드롬 수.
        if (isFel) {
            cout << "yes" << '\n';
        }
        // isFel이 false라면 팰린드롬 수가 아님.
        else {
            cout << "no" << '\n';
        }
        cin >> num;
    }

    return 0;
}