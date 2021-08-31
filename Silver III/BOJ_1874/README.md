# BOJ_1874 - 스택 수열

&nbsp;

## 문제/코드 링크

- [BOJ_1874 - 스택 수열](https://www.acmicpc.net/problem/BOJ_1874)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `st.empty()` or `st.top() < info[infoIdx]`인 경우 `numList[numListIdx]`를 `st`에 넣어준다.

- `st.top() == info[infoIdx]`가 `true`인 경우 `st.top() == info[infoIdx]`이 `false`가 될 때까지 `while`을 반복 실행해준다.

- `st.top() > info[infoIdx]`인 경우 만들 수 없는 수열이므로 `answer.clear()`를 실행하고 `break`로 빠져나온다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> st;
vector<int> info, numList;
vector<char> answer;

int main()
{
    cin >> n;
    info.resize(n);
    numList.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    for (int i = 0; i < n; ++i) {
        numList[i] = i + 1;
    }

    int infoIdx = 0;
    int numListIdx = 1;
    st.push(numList[0]);
    answer.push_back('+');
    while (infoIdx < n) {
        if (st.empty() || st.top() < info[infoIdx]) {
            st.push(numList[numListIdx]);
            ++numListIdx;
            answer.push_back('+');
        }
        else if (st.top() == info[infoIdx]) {
            while (!st.empty() && infoIdx < n && st.top() == info[infoIdx]) {
                st.pop();
                ++infoIdx;
                answer.push_back('-');
            }
        }
        else {
            answer.clear();
            break;
        }
    }

    if (!answer.empty()) {
        int answerSize = answer.size();
        for (int i = 0; i < answerSize; ++i) {
            cout << answer[i] << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}
```
