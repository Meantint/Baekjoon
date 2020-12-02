# BOJ_7662 - 이중 우선순위 큐

&nbsp;처음에 우선순위 큐 두 개를 이용해서 풀었는데 계속 똑같은 곳에서 틀려서 안됐다. 문제가 없는거 같은데 오래보고 있으니 너무 답답해서 `set`을 이용해서 풀었다. 근데 `set`을 이용했을 때도 똑같은 퍼센트에서 틀렸다고 나왔다. 내가 의심이 가는 부분은 테스트케이스가 끝나고 제대로 안지워서 그런게 아닌가 싶다(`set`을 이용할 때 `clear()`를 추가해서 맞췄기 때문에). 답답

- Baekjoon - [이중 우선순위 큐](https://www.acmicpc.net/problem/7662)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 중복이 허용되는 `multiset`을 이용하였다.

- `D -1`인 경우 `ms.begin()`을 지운다.

- `D 1`인 경우 `--(ms.end())`를 지운다.

- `I n`인 경우 `ms.insert(n)`을 해준다.

- 출력할 때 `ms.empty()`가 `true`인 경우 `EMPTY`를 리턴해주고 `false`인 경우 `*(--ms.end())`와 `*ms.begin()`을 출력한다.

## Code

```cpp
#include <iostream>
#include <set>

using namespace std;

int t, n, x;
char c;
multiset<int> ms;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        ms.clear();
        cin >> n;
        while (n--) {
            cin >> c >> x;
            if (c == 'I') {
                ms.insert(x);
            }
            else {
                if (x == 1) {
                    // 비어있지 않으면
                    if (!ms.empty()) {
                        ms.erase(--(ms.end()));
                    }
                }
                else {
                    if (!ms.empty()) {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}
```
