# BOJ_14003 - 가장 긴 증가하는 부분 수열 5

&nbsp;예전에 풀었던 문제가 재채점 되고 나서 시간 초과 처리가 되었다. 그래서 다시 풀었다.

- Baekjoon - [가장 긴 증가하는 부분 수열 5](https://www.acmicpc.net/problem/14003)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이 문제의 경우 `n`의 최대 크기가 `1,000,000`이므로 기존의 방식(LIS 배열에서 순차적으로 탐색해 위치를 찾아내는 방법)으로 했을 경우 `O(n^2)`이라는 시간 복잡도가 나오기 때문에 시간 초과가 난다. 여기서 시간 복잡도가 `O(nlogn)` 이하로 나와야 문제를 통과할 수 있다는 것을 알 수 있다.

- `LIS`를 담은 배열 `info`는 인덱스가 꼬일 수는 있으나 항상 오름차순을 유지한다. 항상 오름차순이라는 것은 탐색에 있어서 이분 탐색을 적용할 수 있다는 말이다. 기존의 `O(n^2)`을 `O(nlogn)`으로 바꿀 수 있다.

## Code

```cpp
#include <iostream>
#include <vector>

#define INF 2112345678

using namespace std;

int n;
vector<int> arr, dp;
vector<int> info;

void LIS_Find(int start, int end, int index)
{
    int ret = -1;
    int mid;

    while (start <= end) {
        mid = ((start + end) >> 1);

        if (info[mid] < arr[index]) {
            start = mid + 1;
        }
        else if (info[mid] == arr[index]) {
            ret = mid;

            break;
        }
        else {
            ret = mid;

            end = mid - 1;
        }
    }

    if (ret == -1) {
        dp[index] = info.size();
        info.push_back(arr[index]);
    }
    else {
        dp[index] = ret;
        info[ret] = arr[index];
    }
}

int main()
{
    cin >> n;

    arr.resize(n);
    dp.resize(n, INF);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    info.push_back(arr[0]);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        int info_size = info.size();

        LIS_Find(0, info_size - 1, i);
    }

    int find = info.size() - 1;
    vector<int> answer(find + 1);
    for (int i = n - 1; i >= 0; --i) {
        if (find == dp[i]) {
            answer[find] = arr[i];
            --find;

            if (find == -1) {
                break;
            }
        }
    }

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}
```
