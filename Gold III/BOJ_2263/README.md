# BOJ_2263 - 트리의 순회

&nbsp;분할 정복

## 문제/코드 링크

- [BOJ_2263 - 트리의 순회](https://www.acmicpc.net/problem/2263)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 중위순회(`inorder`) : `LVR`

- 후위순회(`postorder`) : `LRV`

- 후위순회에서의 마지막 윈소가 전위순회에서의 첫번째 읽히는 원소와 같다(항상).

- 처음 시작할 때는 `inorder`와 `postorder`의 시작과 끝 인덱스가 똑같지만 나중에는 서로의 인덱스 시작 위치, 끝 위치가 다를 수 있으므로 따로 나눠서 관리해야한다.

- 후위순회에서 고른 타겟을 중위순회에서의 위치를 찾아준 후, 그 위치를 기준으로 `left`, `right`를 나눠준다.

- 전위순회는 방문한 곳을 출력한 후에 `left`, `right` 순으로 방문하기 때문에 후위순회에서 고른 타겟을 바로 출력해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;
int inorder[100000];
int postorder[100000];

void dc(int in_lo, int in_hi, int post_lo, int post_hi)
{
    if (in_lo > in_hi || post_lo > post_hi) {
        return;
    }
    int cur = postorder[post_hi];
    // VLR, V
    cout << cur << ' ';
    // 최소 단위라면
    if (post_lo == post_hi) {
        return;
    }

    int target_idx;
    for (int i = in_lo; i <= in_hi; ++i) {
        if (inorder[i] == cur) {
            target_idx = i;
            break;
        }
    }
    // VLR, L
    dc(in_lo, target_idx - 1, post_lo, post_lo + target_idx - in_lo - 1);
    // VLR, R
    dc(target_idx + 1, in_hi, post_lo + target_idx - in_lo, post_hi - 1);
}

void solve()
{
    dc(0, n - 1, 0, n - 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
    solve();

    return 0;
}
```
