# BOJ_3568 - iSharp

&nbsp;값 받는 것에 신경을 쓴 후 구현만 잘해주면 된다.

- Baekjoon - [iSharp](https://www.acmicpc.net/problem/3568)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 입력 받은 값의 사이즈를 `t_size`에 저장한다.

- 기본 베이스(자료형)을 `base` 배열에 저장한다.

- `,` 혹은 `;`를 만나기 전까지가 하나의 변수이므로 만나기 전까지 받아준다.

- `answer`에 `base` + `변수명을 제외한 나머지 역순` + ` ` + `변수명` + `;`를 넣어준다.

## Code

```cpp
#include <iostream>

using namespace std;

char answer[100][130];
int a_size = -1;

char text[130];
int t_size = 0;

char base[130];
int b_size;

char name[130], symbol[130];
int n_idx = -1, s_idx = -1;

void solve()
{
    int idx = 0;

    // 베이스
    for (; idx < t_size; ++idx) {
        if (text[idx] == ' ') {
            b_size = idx;
            ++idx;

            break;
        }
        base[idx] = text[idx];
    }

    for (; idx < t_size; ++idx) {
        if ((text[idx] >= 'A' && text[idx] <= 'Z') || (text[idx] >= 'a' && text[idx] <= 'z')) {
            name[++n_idx] = text[idx];
        }
        else {
            while (text[idx] != ',' && text[idx] != ';') {
                symbol[++s_idx] = text[idx];
                ++idx;
            }

            ++a_size;
            for (int i = 0; i < b_size; ++i) {
                answer[a_size][i] = base[i];
            }
            for (int i = s_idx; i >= 0; --i) {
                if (symbol[i] == ']') {
                    answer[a_size][b_size + s_idx - i] = '[';
                }
                else if (symbol[i] == '[') {
                    answer[a_size][b_size + s_idx - i] = ']';
                }
                else {
                    answer[a_size][b_size + s_idx - i] = symbol[i];
                }
            }
            answer[a_size][b_size + s_idx + 1] = ' ';
            for (int i = 0; i <= n_idx; ++i) {
                answer[a_size][b_size + s_idx + 1 + i + 1] = name[i];
            }
            answer[a_size][b_size + s_idx + 1 + n_idx + 1 + 1] = ';';
            n_idx = -1, s_idx = -1;

            ++idx;
            // cout << name << ", " << symbol << '\n';
        }
    }
    for (int i = 0; i <= a_size; ++i) {
        int j = 0;
        while (answer[i][j] != ';') {
            cout << answer[i][j++];
        }
        cout << ';' << '\n';
    }
}

int main()
{
    cin.getline(text, 130);
    while (text[t_size] != '\0') {
        ++t_size;
    }

    solve();
}
```
