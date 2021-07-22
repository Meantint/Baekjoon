# BOJ_1275 - 커피숍2

&nbsp;세그먼트 트리 사용 문제

- Baekjoon - [커피숍2](https://www.acmicpc.net/problem/1275)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 기본적인 세그먼트 트리의 `init`, `update`, `query` 함수의 구조를 가진다.

- 하지만 이 문제의 경우 기본 입력 배열인 `value`를 `update` 함수 호출할 때 마다 `value[target_index - 1]`을 갱신해야한다. 갱신하지 않으면 2번 이상의 동일 인덱스 접근 시 정상적인 처리가 되지 않는다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, q;
int tree_size = 1;
vector<ll> value;
vector<ll> seg;

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);

    return seg[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int target_index, ll diff)
{
    if (target_index < left || right < target_index) {
        return;
    }

    seg[node] += diff;
    if (left != right) {
        int mid = ((left + right) >> 1);
        update(node * 2, left, mid, target_index, diff);
        update(node * 2 + 1, mid + 1, right, target_index, diff);
    }
}

ll query(int node, int left, int right, int start, int end)
{
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

    cin >> n >> q;
    while (tree_size < n) {
        tree_size *= 2;
    }
    value.resize(n);
    seg.resize(tree_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int x, y, target_index;
        ll v;
        cin >> x >> y >> target_index >> v;

        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
        update(1, 0, n - 1, target_index - 1, v - value[target_index - 1]);
        value[target_index - 1] = v;
    }

    return 0;
}
```
