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