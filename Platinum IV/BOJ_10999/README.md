# BOJ_10999 - 구간 합 구하기 2

&nbsp;세그먼트 트리와 Lazy Propagation을 사용하는 문제.

- Baekjoon - [구간 합 구하기 2](https://www.acmicpc.net/problem/10999)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `propagte` 함수를 선언하였다.

  - 현재 노드로 부터 아래 노드로 전파할 값이 있다면 왼쪽, 오른쪽 자식노드에 `lazy` 값을 전파해준다.

  - 현재 노드를 업데이트 해줘야하기 때문에 `seg[node] += (ll)(right - left + 1) * (ll)lazy[node]`를 실행해준다.

  - 현재 노드의 업데이트가 완료되었기 때문에 `lazy[node] = 0`을 실행해준다.

- `update` 함수를 선언하였다.

  - 맨 앞에 `propagate` 함수가 오는 이유는 if문 두 개를 지나치고 왼쪽, 오른쪽 자식 노드로 재귀 호출 되는 경우 현재 노드가 업데이트 및 하위 노드로 전파되지 않으면 원하지 않는 방향으로 갱신이 되는 경우가 있다. 이러한 경우를 막기 위해 `propagate` 함수를 최상단에 호출해준다.

- `query` 함수를 선언하였다.

  - `update` 함수와 같은 이유로 `propagate` 함수 호촐이 최상단에 위치한다.

  - 현재의 `left` 값과 `right` 값이 `start ~ end`에 속한다면 `seg[node]` 값을 반환해주는데 `update`와 다르게 `propagate` 함수를 호출하지 않는 이유는 최상단에서 `propagate` 함수를 호출했을 때 이미 현재의 노드는 업데이트가 되었기 때문이다. `update` 함수에서는 `lazy[node]` 값을 변경하기 때문에 이에 대한 업데이트를 위해 한 번 더 `propagate` 함수를 실행시키는 것이다.

- 나머지의 경우 일반 세그먼트 트리와 굉장히 유사한 구조다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m, k;
vector<int> value, lazy;
vector<ll> seg;

void propagate(int node, int left, int right)
{
    if (lazy[node] != 0) {
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += (ll)(right - left + 1) * (ll)lazy[node];
        lazy[node] = 0;
    }
}

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);
    return seg[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int start, int end, int change)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        lazy[node] += change;
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, change);
    update(node * 2 + 1, mid + 1, right, start, end, change);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];

    return;
}

ll query(int node, int left, int right, int start, int end)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return 0;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);
    return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    value.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size *= 2;
    }
    seg.resize(seg_size * 2);
    lazy.resize(seg_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m + k; ++i) {
        int case_num;
        cin >> case_num;

        // Update
        if (case_num == 1) {
            int start, end, change;
            cin >> start >> end >> change;

            update(1, 0, n - 1, start - 1, end - 1, change);
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
        }
    }

    return 0;
}
```
