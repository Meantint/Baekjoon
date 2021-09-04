# BOJ_5430 - AC

&nbsp;배열의 크기를 가져와서 `left index`, `right index`를 `update` 하는 식으로 문제를 풀었다. `deque`를 썼으면 굉장히 쉬운 문제이다.

## 문제/코드 링크

- [BOJ_5430 - AC](https://www.acmicpc.net/problem/5430)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `low > high` : `error` 출력

- `low = high` : `[]` 출력

  - `low` ~ `high - 1` 범위를 출력하는 것이므로 `low = high`인 경우는 원소의 크기가 `0`이라고 생각할 수 있다.

- `low < high` : `isRv`가 `true`라면 역순 출력, `false`라면 그냥 출력한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {  //test case
        // input & init
        string order, str;
        int n;
        vector<int> info;
        cin >> order >> n >> str;

        // create array
        if (n != 0) {
            int val = 0;
            int size = str.size();
            for (int i = 1; i < size; ++i) {
                if (str[i] == ',' || str[i] == ']') {
                    info.push_back(val);
                    val = 0;
                }
                else {
                    val *= 10;
                    val += (str[i] - '0');
                }
            }
        }

        // order
        bool isRv = false;  // 뒤집혔는지
        int low = 0, high = info.size();
        int oSize = order.size();
        for (int i = 0; i < oSize; ++i) {
            if (order[i] == 'R') {
                isRv = !isRv;
            }
            else {  // 'D'
                if (isRv) {
                    --high;
                }
                else {
                    ++low;
                }
            }
        }
        if (low > high) {
            cout << "error";
        }
        else if (low == high) {
            cout << "[]";
        }
        else {
            cout << '[';
            if (isRv) {
                for (int i = high - 1; i > low; --i) {
                    cout << info[i] << ',';
                }
                cout << info[low];
            }
            else {
                for (int i = low; i < high - 1; ++i) {
                    cout << info[i] << ',';
                }
                cout << info[high - 1];
            }
            cout << ']';
        }
        cout << '\n';
    }

    return 0;
}
```
