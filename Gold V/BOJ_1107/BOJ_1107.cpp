#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int target, broken;
vector<bool> btn(10, true);

int BFS()
{
    int ret = abs(target - 100);

    vector<bool> isVisited(1000001, false);
    queue<pair<int, int>> q;  // first : current number, second : move count

    for (int i = 0; i < 10; ++i) {
        if (btn[i]) {
            q.push(make_pair(i, 1));
            isVisited[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int curMove = q.front().second;
        q.pop();

        int temp = abs(target - cur) + to_string(cur).size();
        if (ret > temp) {
            ret = temp;
        }

        cur *= 10;
        for (int i = 0; i < 10; ++i) {
            if (btn[i]) {
                int next = cur + i;
                if (next < 1000001 && !isVisited[next]) {
                    q.push(make_pair(next, curMove + 1));
                    isVisited[next] = true;
                }
            }
        }
    }

    return ret;
}

int main()
{
    cin >> target >> broken;
    for (int i = 0; i < broken; ++i) {
        int num;
        cin >> num;

        btn[num] = false;
    }

    cout << BFS() << '\n';

    return 0;
}