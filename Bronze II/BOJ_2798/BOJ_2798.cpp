#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int sum;
int answer = -1;
vector<int> v;

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum = v[i] + v[j] + v[k];
                // 세 숫자의 합이 원하는 값을 넘어간다면 continue 해준다.
                if (sum > m) {
                    continue;
                }
                // sum이 m보다 작거나 같기 떄문에 answer보다 큰 경우 무조건 m과 더 가깝다.
                else if (answer < sum) {
                    answer = sum;
                }
            }
        }
    }
    cout << answer << '\n';

    return 0;
}