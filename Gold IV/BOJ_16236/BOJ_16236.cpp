#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

pair<int, int> shark;
int sizeOfShark = 2;  // 상어 크기
int needFish = 2;     // 크기 키우는데 필요한 물고기

bool isSafe(int y, int x)
{
    if (n <= y || y < 0 || n <= x || x < 0) {
        return false;
    }
    return true;
}

int BFS()
{
    int ret = 0;
    while (1) {
        vector<pair<int, int>> pos;  // 가능한 좌표 모아두기
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push(make_pair(shark.first * 20 + shark.second, 0));
        isVisited[shark.first][shark.second] = true;
        while (!q.empty()) {
            int y = q.front().first / 20;
            int x = q.front().first % 20;
            int dist = q.front().second;
            q.pop();

            // cout << "y, x : " << y << ", " << x << '\n';

            if (board[y][x] != 0 && board[y][x] < sizeOfShark) {  // (y, x)에 잡아먹을 수 있는 물고기가 있을 때
                // cout << "Find\n";
                if (!pos.empty()) {                   // 물고기 위치를 하나라도 찾았을 때
                    if (pos.back().second != dist) {  // 가장 가까운 거리와 현재 거리가 상이할 때 종료
                        break;
                    }
                    else {  // 같은 경우 추가
                        pos.push_back(make_pair(y * 20 + x, dist));
                        continue;  // 추가된 경우 더 거리가 먼 경우를 탐색할 필요 없다.
                    }
                }
                else {
                    pos.push_back(make_pair(y * 20 + x, dist));
                    continue;  // 추가된 경우 더 거리가 먼 경우를 탐색할 필요 없다.
                }
            }

            for (int i = 0; i < 4; ++i) {
                int cy = y + dy[i];
                int cx = x + dx[i];

                if (isSafe(cy, cx) && board[cy][cx] <= sizeOfShark && !isVisited[cy][cx]) {
                    q.push(make_pair(cy * 20 + cx, dist + 1));
                    isVisited[cy][cx] = true;
                }
            }
        }
        if (pos.empty()) {  // 먹을게 없는 경우
            return ret;
        }
        sort(pos.begin(), pos.end());
        shark = make_pair(pos[0].first / 20, pos[0].first % 20);  // 조건에 맞는 위치로 상어 이동
        board[shark.first][shark.second] = 0;                     // 이동한 위치의 값을 0으로 만든다.
        ret += pos[0].second;                                     // 거리만큼 더해준다.
        --needFish;                                               // 필요한 물고기를 하나 제거한다.
        if (needFish == 0) {                                      // 필요 물고기 수를 채웠다면
            needFish = ++sizeOfShark;                             // 상어 크기를 증가시키고 needFish 갱신
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
            if (board[r][c] == 9) {
                shark = make_pair(r, c);
                board[r][c] = 0;
            }
        }
    }

    cout << BFS() << '\n';

    return 0;
}