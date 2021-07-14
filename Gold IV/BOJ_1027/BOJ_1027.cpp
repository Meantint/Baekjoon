#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<ll> h;
vector<int> answer;

int main()
{
    cin >> n;
    h.resize(n);
    answer.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (ll i = 0; i < n; ++i) {
        vector<pair<int, int>> info;
        for (ll j = i + 1; j < n; ++j) {
            if (info.empty()) {
                info.push_back(make_pair(1, h[j] - h[i]));
                ++answer[i];
                ++answer[j];

                continue;
            }

            if (info.back().second * (j - i) < info.back().first * (h[j] - h[i])) {
                info.push_back(make_pair(j - i, h[j] - h[i]));
                ++answer[i];
                ++answer[j];
            }
        }
    }

    int ret = 0;
    for (auto a : answer) {
        if (ret < a) {
            ret = a;
        }
    }
    cout << ret << '\n';

    return 0;
}