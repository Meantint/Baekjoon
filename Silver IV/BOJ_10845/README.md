# BOJ_10845 - 큐

&nbsp;`queue`을 이용하여 풀었다.

- Baekjoon - [큐](https://www.acmicpc.net/problem/10845)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에서 요구하는대로 `queue`을 이용하여 코드를 작성하면 된다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, num;
string str;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> str;

        if (str == "push") {
            cin >> num;
            q.push(num);
        }
        else if (str == "pop") {
            if (q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (str == "size") {
            cout << q.size() << '\n';
        }
        else if (str == "empty") {
            // queue가 비어있다면 1을 리턴
            if (q.empty()) {
                cout << '1' << '\n';
            }
            // queue가 비어있지 않다면 0을 리턴
            else {
                cout << '0' << '\n';
            }
        }
        else if (str == "front") {
            if (q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        // str == "back"
        else {
            if (q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}
```
