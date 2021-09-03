# BOJ_10828 - 스택

&nbsp;`stack`을 이용하여 풀었다.

## 문제/코드 링크

- [BOJ_10828 - 스택](https://www.acmicpc.net/problem/10828)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에서 요구하는대로 `stack`을 이용하여 코드를 작성하면 된다.

## Code

```cpp
#include <iostream>
#include <stack>

using namespace std;

int n, num;
string str;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        // 공백까지 입력받기 위해서
        cin >> str;
        if (str == "pop") {
            // 비어있다면 -1 출력
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            // 비어있지 않다면 st.top()을 출력 후 삭제
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (str == "size") {
            cout << st.size() << '\n';
        }
        else if (str == "empty") {
            if (st.empty()) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
        else if (str == "top") {
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
        // str == "push"
        else {
            // X
            cin >> num;
            st.push(num);
        }
    }

    return 0;
}
```
