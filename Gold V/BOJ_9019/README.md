# BOJ_9019 - DSLR

&nbsp;예전에도 엄청 오래걸렸던 것 같은데 미리 `string` 변수를 4개 선언해놓는 것이 시간에 왜그렇게 큰 영향을 끼치는지 아직 잘 모르겠다. `isVisited[index]`가 `false`인 경우에 굳이 `string` 변수를 선언할 필요가 없는 경우가 생기지만 '그래도 4개 밖에 안되는데?' 라는 생각이 너무 많이 든다. 흠..

## 문제/코드 링크

- [BOJ_9019 - DSLR](https://www.acmicpc.net/problem/9019)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 이 문제 같은 경우 4가지 변화 모두 수식으로 표현이 가능하다.

  - 나는 `L`과 `R`을 `string` 변수로 두고 풀었는데 틀렸다. 이건 확실히 시간 차이가 엄청나게 날 것 같다.

- 다음으로 넘어갈 때의 명령어를 미리 선언해두면(Code 주석에 `47 ~ 50` line) 시간초과가 난다.

  - 조금 더 오래걸릴것이라고는 생각이 드는데 시간초과와 정답을 가를 정도로 큰 영향을 끼치나..?라는 생각에 의문이 든다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int tc;

string BFS(int from, int to)
{
    vector<bool> isVisited(10001, false);
    queue<pair<int, string>> q;  // first : value, second : order

    q.push(make_pair(from, ""));
    isVisited[from] = true;
    while (!q.empty()) {
        int curValue = q.front().first;
        string curOrder = q.front().second;
        q.pop();

        if (curValue == to) {
            return curOrder;
        }

        // push
        // string DO = curOrder + 'D';
        // string SO = curOrder + 'S';
        // string LO = curOrder + 'L';
        // string RO = curOrder + 'R';
        int DV = (curValue * 2) % 10000;
        int SV = (curValue + 9999) % 10000;
        int LV = (curValue % 1000) * 10 + curValue / 1000;
        int RV = (curValue / 10) + (curValue % 10) * 1000;
        if (!isVisited[DV]) {
            isVisited[DV] = true;
            q.push(make_pair(DV, curOrder + 'D'));
            // q.push(make_pair(DV, DO));
        }
        if (!isVisited[SV]) {
            isVisited[SV] = true;
            q.push(make_pair(SV, curOrder + 'S'));
            // q.push(make_pair(SV, SO));
        }
        if (!isVisited[LV]) {
            isVisited[LV] = true;
            q.push(make_pair(LV, curOrder + 'L'));
            // q.push(make_pair(LV, LO));
        }
        if (!isVisited[RV]) {
            isVisited[RV] = true;
            q.push(make_pair(RV, curOrder + 'R'));
            // q.push(make_pair(RV, RO));
        }
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int from, to;
        cin >> from >> to;

        cout << BFS(from, to) << '\n';
    }

    return 0;
}
```
