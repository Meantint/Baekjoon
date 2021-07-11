#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int t, p, x, y;
PII home, fest;
vector<PII> v;

// bool dfs(PII cur, vector<bool> isVisited)
// {
//     // 찾으면
//     if (abs(cur.first - fest.first) + abs(cur.second - fest.second) <= 1000) {
//         return true;
//     }
//     int vSize = v.size();
//     for (int i = 0; i < vSize; ++i) {
//         if (isVisited[i]) continue;
//         if (abs(cur.first - v[i].first) + abs(cur.second - v[i].second) <= 1000) {
//             isVisited[i] = true;
//             if (dfs(v[i], isVisited)) return true;
//             isVisited[i] = false;
//         }
//     }
//     return false;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        v.clear();
        cin >> p >> home.first >> home.second;

        vector<bool> isVisited(p, false);
        while (p--) {
            PII tmp;
            cin >> tmp.first >> tmp.second;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        cin >> fest.first >> fest.second;
        // if (dfs(home, isVisited)) {
        //     cout << "happy\n";
        // }
        // else {
        //     cout << "sad\n";
        // }
        bool isFull = true;
        queue<PII> q;
        q.push(home);
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (abs(cx - fest.first) + abs(cy - fest.second) <= 1000) {
                cout << "happy" << '\n';
                isFull = false;
                break;
            }
            for (int i = 0; i < v.size(); ++i) {
                if (isVisited[i]) continue;
                if (abs(cx - v[i].first) + abs(cy - v[i].second) <= 1000) {
                    q.push(v[i]);
                    isVisited[i] = true;
                }
            }
        }
        if (isFull) {
            cout << "sad\n";
        }
    }

    return 0;
}