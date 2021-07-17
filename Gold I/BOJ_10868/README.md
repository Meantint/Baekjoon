# BOJ_10868 - 최솟값

&nbsp;세그먼트 트리 문제

- Baekjoon - [최솟값](https://www.acmicpc.net/problem/10868)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `init` 함수 작성

  - 리프 노드인 경우 `seg[node] = cost[left]` 실행

  - 리프 노드가 아닌 경우 왼쪽 서브 트리와 오른쪽 서브 트리 중 더 작은 값을 `seg[node]`에 저장한다.

- `query` 함수 작성

  - 범위 벗어나면 `return INF` 실행

  - 완전히 범위 안이라면 `return seg[node]` 실행

  - 범위에 걸쳐 있다면 왼쪽, 오른쪽으로 재귀 분할하여 둘 중 최솟값을 리턴해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define INF 2112345678

using namespace std;

int n, m;
vector<int> cost;
vector<int> seg;

int init(int node, int left, int right)
{
    if (left == right) {
        return (seg[node] = cost[left]);
    }
    else {
        int mid = ((left + right) >> 1);
        int left_value = init(node * 2, left, mid);
        int right_value = init(node * 2 + 1, mid + 1, right);

        return seg[node] = (left_value < right_value ? left_value : right_value);
    }
}

int query(int node, int left, int right, int start, int end)
{
    // 범위 벗어난다면
    if (end < left || right < start) {
        return INF;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }
    else {
        int mid = ((left + right) >> 1);
        int left_value = query(node * 2, left, mid, start, end);
        int right_value = query(node * 2 + 1, mid + 1, right, start, end);

        return left_value < right_value ? left_value : right_value;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size <<= 1;
    }
    seg.resize(seg_size * 2, INF);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
    }

    return 0;
}
```
