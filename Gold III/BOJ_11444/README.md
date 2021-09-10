# BOJ_11444 - 피보나치 수 6

&nbsp;분할정복으로 푸는 문제인 것은 알았는데 피보나치가 분할정복이 되나?라는 생각이 들었던 문제. 행렬 곱셈으로도 피보나치를 구할 수 있다는 것을 오늘 처음 알았다.

&nbsp;다시 한 번 풀었던 코드가 조금 더 깔끔해서 업데이트 했다.

## 문제/코드 링크

- [BOJ_11444 - 피보나치 수 6](https://www.acmicpc.net/problem/11444)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 피보나치를 행렬로 나타내기 위해 `vector<vector<ll>>` 변수 `matrix`를 만들었다.

- 행렬곱셈으로 나타낸 피보나치는 분할정복이 적용 가능하기 때문에 분할 정복 함수 `DC`와 행렬 곱셈을 처리하는 함수 `Cal`을 만들었다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000007

using namespace std;

ll n;
vector<vector<ll>> matrix = {{0, 1}, {1, 1}};

vector<vector<ll>> Cal(vector<vector<ll>> m1, vector<vector<ll>> m2)
{
    vector<vector<ll>> ret(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ret[i][j] += m1[i][k] * m2[k][j];
            }
            ret[i][j] %= MOD;
        }
    }

    return ret;
}

vector<vector<ll>> DC(ll k)
{
    if (k == 1) {
        return matrix;
    }

    if (k % 2 == 0) {
        vector<vector<ll>> temp = DC(k / 2);
        return Cal(temp, temp);
    }
    else {
        return Cal(DC(k - 1), matrix);
    }
}

int main()
{
    cin >> n;

    vector<vector<ll>> answer = DC(++n);

    cout << answer[0][0] << '\n';

    return 0;
}
```
