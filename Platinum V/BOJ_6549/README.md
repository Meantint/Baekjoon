# BOJ_6549 - 히스토그램에서 가장 큰 직사각형

&nbsp;분할정복으로 풀 수 있는 대표적인 문제이다.

- Baekjoon - [히스토그램에서 가장 큰 직사각형](https://www.acmicpc.net/problem/6549)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 입력의 개수가 아주 많을 수 있으므로 `ios::sync_with_stdio(0)`과 `cin.tie(0)`을 선언해주었다.

- `DC` 함수를 선언하였다.

  - `low`와 `high`는 각각 탐색하는 범위의 왼쪽, 오른쪽 끝을 나타낸다.

  - `low != high`라면 `DC(low, mid, h)`, `DC(mid + 1, high, h)`로 분할해서 각각의 최댓값을 `left_max`와 `right_max`에 저장해준다.

    - `mid = (low + high) / 2`

  - `low == high`라면 최소 단위까지 온 것이기 때문에 현재 인덱스의 값을 반환해준다.

  - 분할한 두 개의 함수 결괏값 또는 두 개의 범위를 모두 포함하는 범위에서 나온 값 중 최댓값이 존재하고 분할한 두 개의 함수는 이미 결괏값이 있으므로 `mid`, `mid + 1`의 범위부터 왼쪽, 오른쪽으로 뻗어나가면서 최댓값을 구해준다.

    - 왼쪽 오른쪽을 선택하는 기준은 둘 중에 더 큰 값을 가지는 방향이다.

    - 왼쪽이나 오른쪽 둘 중 하나가 탐색 범위의 끝에 도달했다면 하나의 방향밖에 고르지 못하기 때문에 아직 끝에 도달하지 못한 방향으로 이동한다.

  - `ret`에는 왼쪽, 오른쪽 `DC` 함수 결괏값 중 더 큰 값이 저장되어 있다. 그러므로 양 범위를 합친 것에서 찾은 최댓값과 비교해서 더 큰 값을 반환해주면 된다.

- `answer`에 정답이 저장돼있으므로 출력해주면 된다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll answer;

ll DC(int low, int high, vector<ll>& h)
{
    ll ret = 0;

    ll left_max, right_max;
    int mid = (low + high) / 2;
    if (low != high) {
        left_max = DC(low, mid, h);
        right_max = DC(mid + 1, high, h);
        ret = (left_max < right_max ? right_max : left_max);

        // 왼쪽, 오른쪽 시작 위치를 지정한다
        ll mid_to_left = mid;
        ll mid_to_right = mid + 1;

        ll h_min = (h[mid + 1] < h[mid] ? h[mid + 1] : h[mid]);
        while (mid_to_left != low || mid_to_right != high) {
            ll temp = (mid_to_right - mid_to_left + (ll)1) * h_min;
            if (ret < temp) {
                ret = temp;
            }

            if (mid_to_left == low) {
                ++mid_to_right;
                if (h_min > h[mid_to_right]) {
                    h_min = h[mid_to_right];
                }
            }
            else if (mid_to_right == high) {
                --mid_to_left;
                if (h_min > h[mid_to_left]) {
                    h_min = h[mid_to_left];
                }
            }
            else {
                if (h[mid_to_left - 1] >= h[mid_to_right + 1]) {
                    --mid_to_left;
                    if (h_min > h[mid_to_left]) {
                        h_min = h[mid_to_left];
                    }
                }
                else {
                    ++mid_to_right;
                    if (h_min > h[mid_to_right]) {
                        h_min = h[mid_to_right];
                    }
                }
            }
        }
        // 마지막 범위는 while문에서 체크하지 않으므로 따로 처리해준다
        ll temp = (mid_to_right - mid_to_left + (ll)1) * h_min;

        return (ret < temp ? temp : ret);
    }
    else {
        return h[low];
    }
}

void solve(vector<ll>& h)
{
    answer = 0;

    int low = 0, high = h.size() - 1;
    answer = DC(low, high, h);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<ll> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        solve(h);

        cout << answer << '\n';
    }

    return 0;
}
```
