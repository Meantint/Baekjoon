#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int BFS(int s, int t)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(s, t), 0));

    while (!q.empty()) {
        int start = q.front().first.first;
        int target = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (start == target) {
            return count;
        }
        if (start > target) {
            continue;
        }

        q.push(make_pair(make_pair(start * 2, target + 3), count + 1));
        q.push(make_pair(make_pair(start + 1, target), count + 1));
    }

    return -1;
}

int main()
{
    cin >> n;
    while (n--) {
        int s, t;
        cin >> s >> t;

        cout << BFS(s, t) << '\n';
    }

    return 0;
}