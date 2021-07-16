# BOJ_2042 - 구간 합 구하기

&nbsp;세그먼트 트리 사용 문제. 개념 보면서 열심히 풀었다.

- Baekjoon - [구간 합 구하기](https://www.acmicpc.net/problem/2042)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `init` 함수 작성

  - 단말 노드인 경우 `seg[node] = cost[left]`를 실행한다.

  - 단말 노드가 아닌 경우 왼쪽 서브 트리의 값과 오른쪽 서브 트리의 값을 `left_tree`, `right_tree`에 저장한 후 `seg[node] = left_tree + right_tree`를 실행한다.

- `update` 함수 작성

  - 변경하고자 하는 `target_index`가 범위 안에 들어있지 않다면 리턴한다.

  - 범위 안에 있는 경우는 `target_index`의 값이 변하면 영향을 받는 위치에 있기 때문에 원래의 값 `cost[target_index]`와 새로운 값 `value`의 차이 값만큼 더해준다.

  - 현재 위치가 단말 노드가 아닌 경우 `target_index`의 값의 영향을 받는 위치가 더 있기 때문에 하위 노드를 탐색하면서 갱신해 준다.

  - main 함수를 보면 `cost[target_index - 1] = value`라는 코드가 있는데 이것을 실행 안해주면 세그먼트 트리는 갱신되어 있지만 실제 값이 저장돼있는 `cost`는 갱신이 안 되어 있으므로 에러가 발생한다. 그러므로 `update` 함수 실행 후 `cost[target_index - 1] = value` 역시 실행시켜줘야 한다.

- `query` 함수 작성

  - 범위에서 완전히 벗어난 경우는 값에 영향을 주면 안 되므로 `return 0` 처리한다.

  - 또한 범위에 완전히 속해 있는 경우 역시 하위 노드를 볼 필요가 없으므로 `return seg[node]` 처리한다.

  - 일부만 범위에 속해 있는 경우 2개의 `query` 함수로 분할하여 얻은 2개의 값을 더해 리턴해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m, k;
vector<ll> cost;
vector<ll> seg;

ll init(int node, int left, int right)
{
    if (left == right) {
        seg[node] = cost[left];
    }
    else {
        int mid = ((left + right) >> 1);
        ll left_tree = init(node * 2, left, mid);
        ll right_tree = init(node * 2 + 1, mid + 1, right);

        seg[node] = left_tree + right_tree;
    }

    return seg[node];
}

void update(int node, int left, int right, int target_index, ll value_diff)
{
    if (left > target_index || target_index > right) {
        return;
    }

    seg[node] += value_diff;
    if (left != right) {
        int mid = ((left + right) >> 1);
        update(node * 2, left, mid, target_index, value_diff);
        update(node * 2 + 1, mid + 1, right, target_index, value_diff);
    }
}

ll query(int node, int left, int right, int target_left, int target_right)
{
    // 범위에서 완전히 벗어난 경우
    if (target_right < left || target_left > right) {
        return 0;
    }
    // 범위 안에 완전히 속해 있는 경우
    if (target_left <= left && right <= target_right) {
        return seg[node];
    }
    else {
        int mid = ((left + right) >> 1);
        ll left_query = query(node * 2, left, mid, target_left, target_right);
        ll right_query = query(node * 2 + 1, mid + 1, right, target_left, target_right);

        return left_query + right_query;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size <<= 1;
    }
    seg.resize(seg_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);
    for (int i = 0; i < m + k; ++i) {
        int case_num;
        cin >> case_num;

        // Change
        if (case_num == 1) {
            int target_index;
            ll value;
            cin >> target_index >> value;

            update(1, 0, n - 1, target_index - 1, value - cost[target_index - 1]);
            cost[target_index - 1] = value;
        }
        // Query
        else {
            int target_left, target_right;
            cin >> target_left >> target_right;

            cout << query(1, 0, n - 1, target_left - 1, target_right - 1) << '\n';
        }
    }

    return 0;
}
```
