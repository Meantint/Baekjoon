# BOJ_2407 - 조합

&nbsp;가장 큰 수인 `100C50`의 값이 약 `100^29` 정도 되기 때문에 `Big Int`를 구현해서 풀었다.

- Baekjoon - [조합](https://www.acmicpc.net/problem/2407)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<vector<string>>` 변수 `dp`를 만들었다.

- `n1`과 `n2`의 합을 구해주는 함수 `cal`을 만들었다.

- `n1`과 `n2`의 사이즈가 다를 수 있기 때문에 사이즈가 작은 수의 앞부분에 사이즈가 같아질 때 까지 `'0'`을 넣어준다.

- 일의 자리 수 부터 계산 하면서 이전의 자릿수에 올림이 있었는지를 확인하는 `carry`가 `true`라면 `++num` 해주고 `carry = false` 해준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<string>> dp(101, vector<string>(101, "0"));

string cal(string n1, string n2)
{
    string tmp = "";

    int size = n1.size() - n2.size();
    if (n1.size() > n2.size()) {
        for (int i = 0; i < size; ++i) {
            n2 = '0' + n2;
        }
    }
    else {
        size *= -1;
        for (int i = 0; i < size; ++i) {
            n1 = '0' + n1;
        }
    }
    bool carry = false;
    for (int i = n2.size() - 1; i >= 0; --i) {
        int num = (n1[i] - '0') + (n2[i] - '0');
        // 이전에 올림이 있었다면
        if (carry) {
            ++num;
            carry = false;
        }
        // 더한 것이 한자리 수라면
        if (num < 10) {
            tmp = (char)('0' + num) + tmp;
        }
        else {
            carry = true;
            tmp = (char)('0' + (num - 10)) + tmp;
        }
    }
    // 끝나고 올림이 남아있다면 추가해준다.
    if (carry) {
        tmp = '1' + tmp;
    }

    return tmp;
}

int main()
{
    dp[1][0] = dp[1][1] = "1";
    for (int i = 2; i < 101; ++i) {
        dp[i][0] = dp[i][i] = "1";
        for (int j = 1; j < i; ++j) {
            dp[i][j] = cal(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    cin >> n >> m;
    cout << dp[n][m] << '\n';

    return 0;
}
```
