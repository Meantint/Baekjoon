#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int len;
int answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; ++i) {
        answer = 0;

        cin >> len;

        vector<int> v = vector<int>(len, 0);
        for (int j = 0; j < len; ++j) {
            cin >> v[j];
        }
        for (int j = 2; j < len - 2; ++j) {
            int max_h = max({v[j - 2], v[j - 1], v[j + 1], v[j + 2]});
            if (v[j] > max_h) {
                answer += (v[j] - max_h);
                j += 2;  // 두 칸 범위 내에서 조망 확보 불가함(이미 index j가 조망 확보 했기에)
            }
        }

        cout << "#" << i + 1 << ' ' << answer << '\n';
    }

    return 0;
}