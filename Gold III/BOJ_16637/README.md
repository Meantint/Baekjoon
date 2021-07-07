# BOJ_16637 - 괄호 추가하기

&nbsp;연산 자체가 완전탐색의 범위 안에 들어있다고 생각하여 완전탐색을 이용하여 풀었다. 오랜만의 알고리즘 재활 훈련이라 어려웠는데 또 은근 빨리 풀었다.

- Baekjoon - [괄호 추가하기](https://www.acmicpc.net/problem/16637)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `cnt` 만큼의 괄호를 씌우고 값을 구해서 최대값을 갱신해주는 함수 `makeG`를 만든다.

- `prev_permutation`을 이용하여 모든 경우를 다 탐색했다(시작과 끝에 괄호가 있는 경우와 괄호가 겹치는 경우는 제외시켜줌)

- 수식의 합을 구해주는 함수 `cal`을 만들고 `makeG` 함수 안에서 사용해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, answer = -2112345678;
int numCnt;
string str;

int cal(vector<int> v)
{
    int cur = str[0] - '0';

    for (int i = 1; i < str.size(); i += 2) {
        char op = str[i];
        // 만약 괄호 안에 들어간 첫 번째 수라면
        if (v[(i + 1) / 2] == 1) {
            int next = str[i + 1] - '0';
            char op2 = str[i + 2];
            if (op2 == '+') {
                next += (str[i + 3] - '0');
            }
            else if (op2 == '-') {
                next -= (str[i + 3] - '0');
            }
            else if (op2 == '*') {
                next *= (str[i + 3] - '0');
            }

            if (op == '+') {
                cur += next;
            }
            else if (op == '-') {
                cur -= next;
            }
            else if (op == '*') {
                cur *= next;
            }
            i += 2;
        }
        // 괄호가 아님
        else {
            int next = str[i + 1] - '0';

            if (op == '+') {
                cur += next;
            }
            else if (op == '-') {
                cur -= next;
            }
            else if (op == '*') {
                cur *= next;
            }
        }
    }

    return cur;
}

void makeG(int cnt)
{
    vector<int> v(numCnt, 0);
    for (int i = 0; i < cnt; ++i) {
        v[i] = 1;
    }

    do {
        bool isGood = true;
        for (int i = 0; i < numCnt - 1; ++i) {
            // 시작과 끝에는 없어야 한다.
            if (v[0] == 1 || v.back() == 1) {
                isGood = false;
                break;
            }
            // 하나라도 붙어 있으면(괄호가 1번 인덱스에서 시작한다면 2번 인덱스에서는 절대 시작할 수 없음)
            if (v[i] + v[i + 1] == 2) {
                isGood = false;
                break;
            }
        }
        if (!isGood) {
            continue;
        }
        answer = max(answer, cal(v));
    } while (prev_permutation(v.begin(), v.end()));
}

int main()
{
    // 길이와 수식 입력
    cin >> n >> str;

    numCnt = n / 2 + 1;
    for (int i = 0; i <= numCnt / 2; ++i) {
        makeG(i);
    }
    cout << answer << '\n';

    return 0;
}
```
