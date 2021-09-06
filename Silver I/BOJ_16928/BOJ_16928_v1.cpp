/* vs BOJ_16928
    나아진 것
        - BFS에 대한 사용이 조금 더 명확해짐

    부족한 것
        - 크기가 굉장히 작기 때문에 현재의 좌표가 ladder인지 snake인지
          배열에다가 따로 명시하는 것이 더 가시성이 돋보인다.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int n, m;
// vector<pair<int, int>> ladder, snake;
map<int, int> ladder, snake;

int BFS()
{
    vector<bool> isVisited(101, false);
    queue<pair<int, int>> q;  // first : current position, second : move count

    q.push(make_pair(1, 0));
    isVisited[1] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (cur == 100) {
            return count;
        }

        for (int i = 1; i <= 6; ++i) {
            if (ladder.find(cur + i) != ladder.end()) {  // cur + i 좌표와 매칭되는 ladder가 있는 경우
                if (!isVisited[cur + i]) {               // 방문한 적이 없다면
                    q.push(make_pair(ladder[cur + i], count + 1));
                    isVisited[cur + i] = true;
                    isVisited[ladder[cur + i]] = true;
                }
            }
            else if (snake.find(cur + i) != snake.end()) {
                if (!isVisited[cur + i]) {
                    q.push(make_pair(snake[cur + i], count + 1));
                    isVisited[cur + i] = true;
                    isVisited[snake[cur + i]] = true;
                }
            }
            else {
                if (!isVisited[cur + i]) {
                    q.push(make_pair(cur + i, count + 1));
                    isVisited[cur + i] = true;
                }
            }
        }
    }

    return -1;  // except
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ladder[v1] = v2;
    }
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        snake[v1] = v2;
    }
    cout << BFS() << '\n';

    return 0;
}