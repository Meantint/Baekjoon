# BOJ_10830 - 행렬 제곱

&nbsp;분할정복 문제. 개인적으로 범위 낚시 하는걸 굉장히 싫어한다. 문제에서 `B`의 범위야 그렇다치고 입력은 `1000`을 받을 수 있는데 출력에서는 `1000`을 출력하면 안되는 경우 같은것들...

## 문제/코드 링크

- [BOJ_10830 - 행렬 제곱](https://www.acmicpc.net/problem/10830)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `DC` 함수 선언

  - `num` : 제곱해야하는 횟수

  - 일반 분할정복 구현과 유사하다.

  - 행렬 결괏값을 리턴해준다.

- `cal` 함수 선언

  - `m1`과 `m2`의 행렬 곱셈 결괏값을 리턴한다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll k;
vector<vector<int>> matrix;

vector<vector<int>> cal(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int k = 0; k < n; ++k) {
                ret[r][c] += m1[r][k] * m2[k][c];
            }
            ret[r][c] %= 1000;
        }
    }

    return ret;
}

vector<vector<int>> DC(ll num)
{
    if (num == 1) {
        return matrix;
    }

    if (num % 2 == 0) {
        vector<vector<int>> temp = DC(num / 2);
        return cal(temp, temp);
    }
    else {
        return cal(DC(num - 1), matrix);
    }
}

int main()
{
    cin >> n >> k;
    matrix.resize(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> matrix[r][c];
            matrix[r][c] %= 1000;
        }
    }

    vector<vector<int>> answer = DC(k);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << answer[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
```
