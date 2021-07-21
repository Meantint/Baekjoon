# BOJ_13925 - 수열과 쿼리 13

&nbsp;세그먼트 트리와 Lazy Propagation을 사용하는 문제. `lazy`를 단순화 시키는 것이 굉장히 어려웠다.

&nbsp;처음 구현에서는 `vector<vector<pair<int, int>>>` 타입으로 `lazy`를 구성하였고 모든 정보가 들어오면 `lazy[node].push_back(make_pair(case_num, v))`의 방식으로 하나하나 저장해놓았다. `case_num`이 `3`인 경우에는 이전에 들어온 값들을 제거하는 방식으로 진행하였는데 이것 역시 시간 초과가 났다.

- Baekjoon - [수열과 쿼리 13](https://www.acmicpc.net/problem/13925)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 기본적인 `Lazy Propagation`의 동작은 [BOJ_10999 - 구간 합 구하기 2](https://github.com/Meantint/Baekjoon/tree/master/Platinum%20IV/BOJ_10999)과 같다.

- 문제에서 `long long` 범위를 벗어나는 경우가 많기 때문에 중간중간에 `MOD`를 사용해서 값을 갱신해줘야한다.

- 이 문제의 경우 `lazy[node]`의 타입이 `int`가 아닌 `pair<int, int>`이다.

  - `first` : 현재 `seg[node]`에 곱해 줄 값을 저장했다.

  - `second` : 현재 `lazy[index].first * seg[node]`의 값에 더해 줄 값을 저장했다.

  - `lazy` 원소들의 디폴트 값은 `(1, 0)`이다.

    - `1 * seg[node] + 0 = seg[node]`

- `update` 함수를 작성했다.

  - 현재 범위가 완전히 구간에 속하는 경우 다음 과정을 거친 후 `propagate` 함수를 호출한다.

    - `case_num == 1`

      - `lazy[node].second += v`를 실행하고 `MOD`로 나눠준다.

    - `case_num == 2`

      - `lazy[node]`의 각각의 원소에 `v`를 곱해주고 `MOD`로 나눠준다.

    - `case_num == 3`

      - `lazy[node] = make_pair(0, v)`를 실행해준다.

        - 이전의 연산과 상관없이 `v`로 값을 바꾸는 것이기 때문에 전체를 초기화 한 후 `v`를 더했다고 생각할 수 있다.

- `propagate` 함수를 작성했다.

  - `first`의 경우는 곱하기로 `a * val + b`의 형태에서 `a`와 `b` 둘에게 모두 영향을 준다. 반면에 `second`의 경우는 `b`에게만 영향을 끼친다. 그렇기 때문에 `first`와 `second`의 연산을 달리해줘야한다.

    - `node * 2`, `node * 2 + 1`에 대한 `first` 연산은 다음과 같다(예시는 `node * 2`만 했으나 `node * 2 + 1`도 동일한 연산)

      - `lazy[node * 2].first *= lazy[node].first`

    - `node * 2`, `node * 2 + 1`에 대한 `second` 연산은 다음과 같다(예시는 `node * 2`만 했으나 `node * 2 + 1`도 동일한 연산)

      - `lazy[node * 2].second *= lazy[node].first`

      - `lazy[node * 2].second += lazy[node].second`

  - 이후 현재 노드를 갱신해주고 `lazy[node]`를 `DEFALUT`로 갱신해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long
#define MOD (ll)1000000007
#define DEFAULT make_pair((ll)1, (ll)0)

using namespace std;

int n, m;
vector<int> value;
vector<ll> seg;
vector<pair<ll, ll>> lazy;

using namespace std;

void propagate(int node, int left, int right)
{
    if (lazy[node] != DEFAULT) {
        if (left != right) {
            lazy[node * 2].first *= lazy[node].first;
            lazy[node * 2].second = lazy[node * 2].second * lazy[node].first + lazy[node].second;
            lazy[node * 2 + 1].first *= lazy[node].first;
            lazy[node * 2 + 1].second = lazy[node * 2 + 1].second * lazy[node].first + lazy[node].second;

            lazy[node * 2].first %= MOD;
            lazy[node * 2].second %= MOD;
            lazy[node * 2 + 1].first %= MOD;
            lazy[node * 2 + 1].second %= MOD;
        }
        seg[node] = (lazy[node].first * seg[node] + (right - left + 1) * lazy[node].second) % MOD;
        lazy[node] = DEFAULT;
    }
}

int init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);
    return seg[node] = (init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right)) % MOD;
}

void update(int node, int left, int right, int start, int end, int case_num, ll v)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        if (case_num == 1) {
            lazy[node].second += v;
            lazy[node].second %= MOD;
        }
        else if (case_num == 2) {
            lazy[node].first *= v;
            lazy[node].first %= MOD;
            lazy[node].second *= v;
            lazy[node].second %= MOD;
        }
        else {
            lazy[node] = make_pair(0, v);
        }
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, case_num, v);
    update(node * 2 + 1, mid + 1, right, start, end, case_num, v);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;

    return;
}

int query(int node, int left, int right, int start, int end)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return 0;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);

    return (query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end)) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    value.resize(n);

    int tree_size = 1;
    while (tree_size < n) {
        tree_size *= 2;
    }
    seg.resize(tree_size * 2);
    lazy.resize(tree_size * 2, DEFAULT);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int case_num;
        cin >> case_num;

        // Update
        if (case_num < 4) {
            int x, y, v;
            cin >> x >> y >> v;

            update(1, 0, n - 1, x - 1, y - 1, case_num, v);
        }
        // Query
        else {
            int x, y;
            cin >> x >> y;

            cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
        }
    }

    return 0;
}
```
