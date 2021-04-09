# BOJ_11444 - 피보나치 수 6

&nbsp;분할정복으로 푸는 문제인 것은 알았는데 피보나치가 분할정복이 되나?라는 생각이 들었던 문제. 행렬 곱셈으로도 피보나치를 구할 수 있다는 것을 오늘 처음 알았다.

- Baekjoon - [피보나치 수 6](https://www.acmicpc.net/problem/11444)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 피보나치를 행렬로 나타내기 위해 `vector<vector<ll>>` 변수 `v`를 만들었다.

- 행렬곱셈으로 나타낸 피보나치는 분할정복이 적용 가능하기 때문에 분할 정복 함수 `dc`와 행렬 곱셈을 처리하는 함수 `cal`을 만들었다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<vector<ll>> v = {
    {1, 1},
    {1, 0},
};
ll n;

vector<vector<ll>> cal(vector<vector<ll>> v1, vector<vector<ll>> v2)
{
    vector<vector<ll>> res(2, vector<ll>(2));

    res[0][0] = ((v1[0][0] * v2[0][0]) % 1000000007 + (v1[0][1] * v2[1][0]) % 1000000007) % 1000000007;
    res[0][1] = ((v1[0][0] * v2[0][1]) % 1000000007 + (v1[0][1] * v2[1][1]) % 1000000007) % 1000000007;
    res[1][0] = ((v1[1][0] * v2[0][0]) % 1000000007 + (v1[1][1] * v2[1][0]) % 1000000007) % 1000000007;
    res[1][1] = ((v1[1][0] * v2[0][1]) % 1000000007 + (v1[1][1] * v2[1][1]) % 1000000007) % 1000000007;

    return res;
}

vector<vector<ll>> dc(ll num)
{
    if (num == 1) {
        return v;
    }

    if ((num & 1) == 0) {
        vector<vector<ll>> res = dc(num / 2);
        return cal(res, res);
    }
    else {
        return cal(dc(num - 1), v);
    }
}

void solve()
{
    vector<vector<ll>> answer = dc(n);

    cout << answer[0][1] << '\n';
}

int main()
{
    cin >> n;

    solve();

    return 0;
}
```
