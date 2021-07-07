#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, l, m;
int answer = 0;
vector<pair<int, int>> save_pos;
vector<int> existY, existX;

int getCount(pair<int, int> pos, int lenY, int lenX)
{
    int ret = 0;

    for (int i = 0; i < m; ++i) {
        if (save_pos[i].first >= pos.first && save_pos[i].first <= pos.first + lenY) {
            if (save_pos[i].second >= pos.second && save_pos[i].second <= pos.second + lenX) {
                ++ret;
            }
        }
    }

    return ret;
}

void solve()
{
    int len = l / 2;

    for (int y = 0; y <= n; ++y) {
        if (existY[y] == 0) {
            continue;
        }
        for (int x = 0; x <= n; ++x) {
            if (existX[x] == 0) {
                continue;
            }

            for (int l = 1; l < len; ++l) {
                int tmp = getCount(make_pair(y, x), l, len - l);
                if (answer < tmp) {
                    answer = tmp;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> l >> m;
    existY = existX = vector<int>(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int y, x;
        cin >> y >> x;

        save_pos.push_back(make_pair(y, x));
        existY[y] = 1;
        existX[x] = 1;
    }

    solve();

    cout << answer << '\n';

    return 0;
}