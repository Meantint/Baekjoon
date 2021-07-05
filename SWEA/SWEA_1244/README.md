# SWEA_1244

&nbsp;`Greedy` 문제이다. 예외 케이스가 꽤 있어서 오래 걸렸다.

- SWEA_1244 - [SWEA_1244](https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=1244&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)

- My SWEA Code : [https://github.com/Meantint/SWEA](https://github.com/Meantint/SWEA)

## 풀이

- 자릿수들의 비교를 조금 더 편하게 하기 위해서 `num`을 `string` 형태로 함수에 넘겨주었다.

- 같은 숫자가 하나라도 있는 경우 내림차순으로 숫자 정렬을 완료하고, 교환 횟수가 남았을 때 교환 횟수와 상관없이 값을 그대로 유지할 수 있기 때문에 같은 숫자가 있는지의 여부를 검사하여 저장해두는 `bool` 변수 `isSame`을 만들어주었다.

- 돈을 가장 많이 받으려면 앞의 자리가 최대한 커야하기 때문에 앞에서 부터 순차적으로 탐색하여 더 큰 값이 있는 경우 `swap` 해주고, 없는 경우에는 다음 자릿수를 탐색해준다.

- 맨 앞자리 보다 큰 수(모든 자릿수의 값 중 최대값)가 있는데 최대값이 여러개인 경우에는 어떤 자리를 바꿨을 때가 가장 큰지를 모르기 때문에 모든 경우를 탐색하여 그 중 가장 큰 값을 `answer`에 저장해두었다.

- 이중 for문을 나왔을 때 `answer`의 값이 `0`인 경우가 있는데 이것은 이미 내림차순으로 정렬이 완료된 경우이다. 이 때 여러가지 경우가 있는데

  - 남은 횟수가 짝수인 경우 : 같은 값이 있는지의 유무와 상관없이 현재의 수를 유지할 수 있으므로 `return stoi(s)` 해준다.

  - 남은 횟수가 홀수인 경우는 다시 두 가지로 나누어진다.

    - `isSame`이 `true`인 경우 현재의 수를 유지할 수 있으므로 `return stoi(s)` 해준다.

    - `isSame`이 `false`인 경우 현재의 수를 유지할 수 없으므로 마지막 두 자리수를 교환한 값을 리턴해준다. 마지막 두 자리수를 교환한 것이 현재의 수 다음으로 큰 수이기 때문이다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int case_num = 1;
int tc = 0;
int num, change;
bool isSame = false;  // 같은 숫자가 존재하는지의 여부
vector<int> num_list;

int solve(string s, int cnt)
{
    if (cnt == 0) {
        return stoi(s);
    }
    // 제한 함수 내에서의 답
    int answer = 0;

    for (int i = 0; i < s.size(); ++i) {
        char max_val = s[i];
        // i(인덱스) 보다 큰 인덱스 값 중 가장 큰 값을 갱신해준다.
        for (int j = i + 1; j < s.size(); ++j) {
            if (max_val < s[j]) {
                max_val = s[j];
            }
        }
        // 가장 큰 숫자가 맨 앞에 있다면 맨 앞의 숫자를 바꿀 필요 X
        if (max_val == s[i]) {
            continue;
        }
        else {
            for (int j = i + 1; j < s.size(); ++j) {
                if (max_val == s[j]) {
                    string cp = s;
                    swap(cp[i], cp[j]);
                    answer = max(answer, solve(cp, cnt - 1));
                }
            }
            break;
        }
    }
    // 숫자가 내림차순으로 정렬이 완료된 경우
    if (answer == 0) {
        // 남은 횟수가 짝수라면
        if (cnt % 2 == 0) {
            return stoi(s);
        }
        // 남은 횟수가 홀수라면
        else {
            // 하나라도 같은 숫자가 있으면 남은 횟수의 의미가 없다
            if (isSame) {
            }
            else {
                swap(s[s.size() - 2], s[s.size() - 1]);
            }
            return stoi(s);
        }
    }

    return answer;
}

int main()
{
    cin >> tc;
    while (tc--) {
        cin >> num >> change;
        // cout << num << ' ' << change << '\n';
        // if (num / 10 == 0) {
        //     cout << '#' << case_num++ << ' ' << num << '\n';
        //     continue;
        // }
        string sv = to_string(num);
        for (int i = 0; i < sv.size(); ++i) {
            for (int j = i + 1; j < sv.size(); ++j) {
                // 하나라도 같은 숫자가 있으면
                if (sv[i] == sv[j]) {
                    isSame = true;
                }
            }
        }

        cout << '#' << case_num++ << ' ' << solve(sv, change) << '\n';
        isSame = false;
    }

    return 0;
}
```
