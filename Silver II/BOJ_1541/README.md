# BOJ_1541 - 잃어버린 괄호

&nbsp;`-`인 경우 다음 `-`를 만나기 전까지의 모든 값들을 합쳐준다(더해준다).

## 문제/코드 링크

- [BOJ_1541 - 잃어버린 괄호](https://www.acmicpc.net/problem/1541)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `num.size()`만큼 반복하는 경우 마지막 숫자를 for문 안에서 `num.push_back()` 해줄 수 없다. 그렇기 때문에 for문이 끝나고 따로 `num.push_back()` 해준다.

- `sv[0] - sv[1] - sv[2] - ... - sv[sv.size() - 1]`이 문제의 정답이다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> num;
vector<char> op;

int main()
{
    cin >> str;
    int size = str.size();
    int val = 0;
    for (int i = 0; i < size; ++i) {
        if ('0' <= str[i] && str[i] <= '9') {
            val *= 10;
            val += (str[i] - '0');
        }
        else {  // +, -
            num.push_back(val);
            val = 0;
            op.push_back(str[i]);
        }
    }
    num.push_back(val);  // 마지막 숫자 넣어주기

    vector<int> sv;  // sv[0] : 기준 숫자, sv[1...] : sv[0]에 빼줘야할 숫자
    sv.push_back(num[0]);
    int oSize = op.size();
    for (int i = 0; i < oSize; ++i) {
        if (op[i] == '+') {
            sv.back() += num[i + 1];
        }
        else {
            sv.push_back(num[i + 1]);
        }
    }
    int answer = sv[0];
    int svSize = sv.size();
    for (int i = 1; i < svSize; ++i) {
        answer -= sv[i];
    }
    cout << answer << '\n';

    return 0;
}
```
