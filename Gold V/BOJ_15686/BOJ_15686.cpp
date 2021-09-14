#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define INF 2112345678;

using namespace std;

int n, m;
int val;
int answer = INF;
vector<vector<int>> dist;
vector<pair<int, int>> home, chicken;

int main()
{
    cin >> n >> m;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> val;
            if (val == 1) {
                home.push_back(make_pair(r, c));
            }
            else if (val == 2) {
                chicken.push_back(make_pair(r, c));
            }
        }
    }
    int cSize = chicken.size(), hSize = home.size();
    dist.resize(cSize, vector<int>(hSize));
    for (int i = 0; i < cSize; ++i) {
        for (int j = 0; j < hSize; ++j) {
            dist[i][j] = abs(chicken[i].first - home[j].first) + abs(chicken[i].second - home[j].second);
        }
    }

    vector<int> comb(cSize, 1);
    for (int i = 0; i < m; ++i) {
        comb[i] = 0;
    }
    do {
        vector<int> temp;
        for (int i = 0; i < cSize; ++i) {
            if (comb[i] == 0) {
                temp.push_back(i);
            }
        }

        int ret = 0;
        for (int h = 0; h < hSize; ++h) {
            int minVal = INF;
            for (int c = 0; c < m; ++c) {
                if (minVal > dist[temp[c]][h]) {
                    minVal = dist[temp[c]][h];
                }
            }
            ret += minVal;
        }
        if (answer > ret) {
            answer = ret;
        }
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer << '\n';

    return 0;
}