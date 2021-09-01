# BOJ_2164 - 카드2

&nbsp;

## 문제/코드 링크

- [BOJ_2164 - 카드2](https://www.acmicpc.net/problem/2164)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 제거를 할 경우에는 가장 앞의 숫자가 마지막 숫자인지 확인하고

  - 마지막 숫자라면 `answer = card.back()` 해주고 `break` 해준다.

  - 마지막 숫자가 아니라면 `++idx`를 해준다.

- 앞의 숫자를 뒤로 넘기는 경우에도 앞의 숫자가 마지막 숫자인지 확인하고

  - 마지막 숫자라면 `answer = card.back()` 해주고 `break` 해준다.

  - 마지막 숫자가 아니라면 `card.push_back(card[idx])`를 해주고 `++idx` 해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n;
int idx = 0, answer = -1;
vector<int> card;

int main()
{
    cin >> n;
    card.resize(n);
    for (int i = 0; i < n; ++i) {
        card[i] = i + 1;
    }
    while (1) {
        // 가장 앞에 있는 숫자가 마지막 숫자가 아니라면 다음 인덱스로 넘어간다.
        if (idx == (int)(card.size() - 1)) {
            answer = card.back();

            break;
        }
        else {
            ++idx;
        }
        // 가장 앞에 있는 숫자를 가장 뒤로 넘겨준다.
        if (idx == (int)(card.size() - 1)) {
            answer = card.back();

            break;
        }
        else {
            card.push_back(card[idx]);
            ++idx;
        }
    }
    cout << answer << '\n';

    return 0;
}
```
