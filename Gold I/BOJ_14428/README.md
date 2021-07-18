# BOJ_14428 - 수열과 쿼리 16

&nbsp;세그먼트 트리. 가장 작은 값을 가진 인덱스를 반환하는 문제이기 때문에 `pair<int, int>`를 썼다.

- Baekjoon - [수열과 쿼리 16](https://www.acmicpc.net/problem/14428)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `init`, `update`, `query` 함수 모두 최솟값이 2개 이상인 경우에는 그 중 가장 작은 인덱스를 반환해야 하기 때문에 따로 처리를 해주었다.

- `seg` 배열의 타입은 `vector<pair<int, int>>`이다.

  - `first : cost[index]`

  - `second : index`

- `init` 함수 작성

  - 단말 노드인 경우 `seg[node] = make_pair(cost[left], left)`를 실행한다.

  - 단말 노드가 아닌 경우 왼쪽 서브 트리의 값과 오른쪽 서브 트리의 값을 `left_info`, `right_info`에 저장하고 더 작은 값을 `seg[node]`에 저장하고 리턴한다.

- `update` 함수 작성

  - 변경하고자 하는 `target_index`가 범위 안에 들어있지 않다면 `make_pair(INF, INF)`를 리턴한다.

  - 단말 노드인 경우에만 `seg[node] = make_pair(new_value, target_index)`를 실행한다.

- `query` 함수 작성

  - `query` 함수의 경우 말 그대로 쿼리를 리턴하는 함수이기 때문에 `seg[node]`의 갱신이 일어나면 안된다!

    - 실수해서 적어놓았다.

  - 범위에서 완전히 벗어난 경우는 값에 영향을 주면 안 되므로 `return make_pair(INF, INF)`를 실행한다.

  - 또한 범위에 완전히 속해 있는 경우 `return seg[node]`를 실행한다.

  - 일부만 범위에 속해 있는 경우 2개의 `query` 함수로 분할하여 얻은 2개의 값 중 더 작은 값의 정보를 리턴한다.

## Code

```cpp
#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, m;
vector<int> cost;
vector<pair<int, int>> seg;

PII init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = make_pair(cost[left], left);
    }

    int mid = ((left + right) >> 1);
    PII left_info = init(node * 2, left, mid);
    PII right_info = init(node * 2 + 1, mid + 1, right);

    if (left_info.first == right_info.first) {
        if (left_info.second < right_info.second) {
            seg[node] = left_info;
        }
        else {
            seg[node] = right_info;
        }
        return seg[node];
    }
    return seg[node] = (left_info.first < right_info.first ? left_info : right_info);
}

PII update(int node, int left, int right, int target_index, int new_value)
{
    if (target_index < left || right < target_index) {
        return seg[node];
    }

    if (left != right) {
        int mid = ((left + right) >> 1);
        PII left_info = update(node * 2, left, mid, target_index, new_value);
        PII right_info = update(node * 2 + 1, mid + 1, right, target_index, new_value);

        if (left_info.first == right_info.first) {
            if (left_info.second < right_info.second) {
                seg[node] = left_info;
            }
            else {
                seg[node] = right_info;
            }
            return seg[node];
        }
        return seg[node] = (left_info.first < right_info.first ? left_info : right_info);
    }
    else {
        return seg[node] = make_pair(new_value, target_index);
    }
}

PII query(int node, int left, int right, int start, int end)
{
    if (right < start || end < left) {
        return make_pair(INF, INF);
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);
    PII left_info = query(node * 2, left, mid, start, end);
    PII right_info = query(node * 2 + 1, mid + 1, right, start, end);

    if (left_info.first == right_info.first) {
        if (left_info.second < right_info.second) {
            return left_info;
        }
        else {
            return right_info;
        }
    }
    return (left_info.first < right_info.first ? left_info : right_info);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size *= 2;
    }
    seg.resize(seg_size * 2);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int case_num;
        cin >> case_num;

        // Change
        if (case_num == 1) {
            int target_index, new_value;
            cin >> target_index >> new_value;

            update(1, 0, n - 1, target_index - 1, new_value);
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1).second + 1 << '\n';
        }
    }

    return 0;
}
```
