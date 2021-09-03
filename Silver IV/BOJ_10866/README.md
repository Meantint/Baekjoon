# BOJ_10866 - 덱

&nbsp;`deque`을 이용하여 풀었다.

## 문제/코드 링크

- [BOJ_10866 - 덱](https://www.acmicpc.net/problem/10866)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에서 요구하는대로 `deque`을 이용하여 코드를 작성하면 된다.

## Code

```cpp
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int n, num;
string str;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;

        if (str == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        else if (str == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if (str == "pop_front") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (str == "pop_back") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (str == "size") {
            cout << dq.size() << '\n';
        }
        else if (str == "empty") {
            if (dq.empty()) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
        else if (str == "front") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        // str == "back"
        else {
            if (dq.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}
```
