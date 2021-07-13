# BOJ_9934 - 완전 이진 트리

&nbsp;흠..잘 풀었다고 생각한다. 내 설명을 본 후 [https://jason9319.tistory.com/136](https://jason9319.tistory.com/136) 블로그의 풀이를 꼭 봤으면 좋겠다. 훨씬 잘 짠 코드 👍(나보다)

- Baekjoon - [완전 이진 트리](https://www.acmicpc.net/problem/9934)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `middle` 함수

  - 현재 받은 배열에서의 가운데 녀석을 `answer[depth]`에 `push_back` 해준다.

  - 리프 노드, `start = end`라면 종료한다.

  - 리프 노드가 아니라면 배열에 넣은 값을 기준으로 (왼쪽, 오른쪽) 범위를 대상으로 다시 `middle` 함수를 실행시킨다.

    - 함수가 깊어질때마다 `depth`는 `1`씩 증가한다.

- `answer` 함수에 `row` 인덱스 순서대로 깊은 값이 들어가 있기 때문에 순서대로 출력하고 `row` 값이 바뀔 때 마다 개행을 추가해준다.

  - 여기서 `row`는 `arr[row][col]`의 `row`

## Code

```cpp
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
int real_size;
vector<int> order;
vector<vector<int>> answer;

void middle(int start, int end, int depth)
{
    // cout << start << ", " << end << ", " << depth << '\n';
    int mid = (start + end) / 2;
    answer[depth].push_back(order[mid]);

    if (start == end) {
        return;
    }

    middle(start, mid - 1, depth + 1);
    middle(mid + 1, end, depth + 1);

    return;
}

int main()
{
    cin >> n;

    real_size = pow(2, n);
    answer.resize(n);
    order.resize(real_size, 0);

    for (int i = 0; i < real_size; ++i) {
        cin >> order[i];
    }

    middle(0, real_size - 2, 0);

    for (int i = 0; i < n; ++i) {
        int size = answer[i].size();
        for (int j = 0; j < size; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
```
