# BOJ_1764 - 듣보잡

&nbsp;`map`을 하나만 만들고 보도 못한 사람들의 입력을 받아 듣지도 못한 사람에도 포함되는지 확인하면 된다.

- Baekjoon - [듣보잡](https://www.acmicpc.net/problem/1764)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 듣도 못한 사람을 `dbj`에 모두 넣는다.

- 보도 못한 사람을 입력 받아 듣도 못한 사람에도 있는지 확인 후 있다면 `answer.push_back()` 해준다.

- `answer`를 사전순 정렬(오름차순 정렬) 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m, idx = 0;
string name = "";
vector<string> answer;
map<string, int> dbj;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        cin >> name;
        dbj[name] = idx;
        ++idx;
    }
    while (m--) {
        cin >> name;
        // 보도 못한 사람 중에 듣지도 못한 사람이 있을 때
        if (dbj.find(name) != dbj.end()) {
            answer.push_back(name);
        }
    }
    // 사전순으로 정렬한다.
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto& ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}
```
