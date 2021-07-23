# BOJ_11656 - 접미사 배열

&nbsp;크기에 신경쓸 필요는 없다.

## 문제/코드 링크

- [BOJ_11656 - 접미사 배열](https://www.acmicpc.net/problem/11656)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 시작 인덱스를 `1`만큼 증가시켜주면서 `answer` 배열에 넣어준다.

- `answer` 배열을 오름차순 정렬해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> answer;

int main()
{
    cin >> str;

    int str_size = str.size();
    for (int i = 0; i < str_size; ++i) {
        answer.push_back(str.substr(i));
    }

    sort(answer.begin(), answer.end());

    for (auto ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}
```
