&nbsp;점의 위치와 반지름에 길이에 따른 교점 갯수를 잘 세어야한다.  컴파일을 하는데 y0, y1...는 이미 함수로 선언되어 있어서 이름을 바꿔줘야했다.

#### Baekjoon - [터렛](https://www.acmicpc.net/problem/1002)
#### My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

<hr>

## 풀이

- 원의 중점이 같을 때

  - 반지름의 길이가 같다면 교점은 무수히 많다

  - 반지름의 길이가 다르다면 교점은 존재하지 않는다.

- 원의 중점이 다를 때

  - 점 두 개 사이의 거리 : `pp`, 두 반지름 길이의 합 : `rr`

  - `pp > rr` 이면 교점은 없다.

  - `pp == rr` 이면 교점은 한 개이다.

  - `pp < rr` 일 때

    - 두 반지름 길이의 차 : `new_rr`

      - `pp < new_rr` 이면 교점은 없다.

      - `pp == new_rr` 이면 교점은 한 개이다.

      - `pp > new_rr` 이면 교점은 두 개이다.

<hr>

## Code
```cpp
#include <cmath>
#include <iostream>

using namespace std;

int t;
int x_1, y_1, r_1, x_2, y_2, r_2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        // 원의 중점이 같고
        if (x_1 == x_2 && y_1 == y_2) {
            // 반지름도 같을 때
            if (r_1 == r_2) {
                cout << "-1\n";
            }
            // 반지름만 다를 때
            else {
                cout << "0\n";
            }
        }
        else {
            int pp = pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2);
            int rr = pow(r_1 + r_2, 2);
            if (pp > rr) {
                cout << "0\n";
            }
            else if (pp == rr) {
                cout << "1\n";
            }
            else {
                int new_rr = pow(r_1 - r_2, 2);
                if (pp < new_rr) {
                    cout << "0\n";
                }
                else if (pp == new_rr) {
                    cout << "1\n";
                }
                else {
                    cout << "2\n";
                }
            }
        }
    }

    return 0;
}
```

<hr>
