# BOJ_11723 - 집합

&nbsp;

## 문제/코드 링크

- [BOJ_11723 - 집합](https://www.acmicpc.net/problem/11723)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector`를 이용해 구현해주면 된다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, x;
string str;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    while (m--) {
        cin >> str;
        if (str == "add") {
            cin >> x;
            // 이미 있으면 true
            bool isCheck = false;
            for (auto& val : v) {
                if (x == val) {
                    isCheck = true;
                    break;
                }
            }
            // 없는 경우 추가 해준다.
            if (!isCheck) {
                v.push_back(x);
            }
        }
        else if (str == "remove") {
            cin >> x;
            int vSize = v.size();
            for (int i = 0; i < vSize; ++i) {
                if (x == v[i]) {
                    v.erase(v.begin() + i);
                    break;
                }
            }
        }
        else if (str == "check") {
            cin >> x;
            // 있으면 true, 없으면 false
            bool isCheck = false;
            for (auto& val : v) {
                if (x == val) {
                    isCheck = true;
                    break;
                }
            }
            if (isCheck) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
        else if (str == "toggle") {
            cin >> x;
            // 있으면 true, 없으면 false
            bool isCheck = false;
            for (auto& val : v) {
                // 있으면 제거
                if (x == val) {
                    isCheck = true;
                    v.erase(v.begin() + (&val - &v[0]));
                    break;
                }
            }
            // 없다면 추가
            if (!isCheck) {
                v.push_back(x);
            }
        }
        else if (str == "all") {
            v = {};
            for (int i = 1; i < 21; ++i) {
                v.push_back(i);
            }
        }
        // str == "empty"
        else {
            v = {};
        }
    }
}
```
