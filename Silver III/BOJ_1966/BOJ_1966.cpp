#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc, n, m;

int main()
{
    cin >> tc;
    while (tc--) {
        int ret = 1;
        vector<int> priority(10, 0);
        queue<pair<int, int>> q;

        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;

            q.push(make_pair(p, i));
            ++priority[p];
        }

        int targetPriority = -1;
        for (int i = 9; i > 0; --i) {
            if (priority[i] != 0) {
                targetPriority = i;
                break;
            }
        }

        while (1) {
            int curPriority = q.front().first;
            int curIdx = q.front().second;
            q.pop();

            if (targetPriority == curPriority) {
                // 정답 case
                if (curIdx == m) {
                    cout << ret << '\n';
                    break;
                }
                else {
                    ++ret;
                    --priority[targetPriority];
                    // 현재 중요도 개수가 0개면 위치 변경
                    while (priority[targetPriority] == 0) {
                        --targetPriority;
                    }
                }
            }
            else {
                // 현재 최우선 중요도가 아니면 다시 queue에 넣는다.
                q.push(make_pair(curPriority, curIdx));
            }
        }
    }

    return 0;
}