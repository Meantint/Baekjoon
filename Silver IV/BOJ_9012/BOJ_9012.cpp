#include <iostream>
#include <string>

using namespace std;

int n, check = 0;
string str;

int main()
{
    cin >> n;
    while (n--) {
        check = 0;
        cin >> str;
        for (auto& c : str) {
            if (c == '(') {
                ++check;
            }
            else {
                --check;
            }
            // 이 때까지 탐색한 결과 '('보다 ')'가 더 많은 경우 VPS가 아니다.
            if (check < 0) {
                break;
            }
        }
        // for문이 끝났을 때 check == 0이라면 VPS이다.
        if (check == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}