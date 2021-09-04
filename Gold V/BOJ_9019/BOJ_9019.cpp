#include <iostream>
#include <queue>
#include <string>

using namespace std;

int tc;

string BFS(int from, int to)
{
    vector<bool> isVisited(10001, false);
    queue<pair<int, string>> q;  // first : value, second : order

    q.push(make_pair(from, ""));
    isVisited[from] = true;
    while (!q.empty()) {
        int curValue = q.front().first;
        string curOrder = q.front().second;
        q.pop();

        if (curValue == to) {
            return curOrder;
        }

        // push
        // string DO = curOrder + 'D';
        // string SO = curOrder + 'S';
        // string LO = curOrder + 'L';
        // string RO = curOrder + 'R';
        int DV = (curValue * 2) % 10000;
        int SV = (curValue + 9999) % 10000;
        int LV = (curValue % 1000) * 10 + curValue / 1000;
        int RV = (curValue / 10) + (curValue % 10) * 1000;
        if (!isVisited[DV]) {
            isVisited[DV] = true;
            q.push(make_pair(DV, curOrder + 'D'));
            // q.push(make_pair(DV, DO));
        }
        if (!isVisited[SV]) {
            isVisited[SV] = true;
            q.push(make_pair(SV, curOrder + 'S'));
            // q.push(make_pair(SV, SO));
        }
        if (!isVisited[LV]) {
            isVisited[LV] = true;
            q.push(make_pair(LV, curOrder + 'L'));
            // q.push(make_pair(LV, LO));
        }
        if (!isVisited[RV]) {
            isVisited[RV] = true;
            q.push(make_pair(RV, curOrder + 'R'));
            // q.push(make_pair(RV, RO));
        }
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int from, to;
        cin >> from >> to;

        cout << BFS(from, to) << '\n';
    }

    return 0;
}