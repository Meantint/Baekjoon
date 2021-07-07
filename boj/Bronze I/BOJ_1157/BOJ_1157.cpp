#include <iostream>
#include <string>

using namespace std;

bool isOne = true;  // 최대값이 하나인지 판별하는 변수
char answer = 'A';
string str;
// 알파벳 카운트
int alpha[26] = {0};

int main()
{
    cin >> str;

    for (auto& c : str) {
        // 소문자일 때
        if (c >= 'a' && c <= 'z') {
            ++alpha[c - 'a'];
        }
        // 대문자일 때
        else if (c >= 'A' && c <= 'Z') {
            ++alpha[c - 'A'];
        }
    }
    for (int i = 1; i < 26; ++i) {
        // 기존의 정답보다 많은 카운트가 됐을 때 -> 갱신
        if (alpha[answer - 'A'] < alpha[i]) {
            answer = i + 'A';
            isOne = true;  // 이전의 최대값이 하나가 아니었을 수 있기 때문에 true로 바꿔준다.
        }
        // 사이즈가 같을 때
        else if (alpha[answer - 'A'] == alpha[i]) {
            isOne = false;  // 하나가 아니므로
        }
    }
    // 최대값이 하나라면
    if (isOne) {
        cout << answer << '\n';
    }
    // 하나가 아니라면
    else {
        cout << '?' << '\n';
    }

    return 0;
}