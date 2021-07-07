#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int board[20][20];
int n, x, y, answer = 0;
int sharkSize = 2;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct comp {
    bool operator()(tuple<int, int, int> t1, tuple<int, int, int> t2)
    {
        if (get<2>(t1) == get<2>(t2)) {
            if (get<0>(t1) == get<0>(t2)) {
                return get<1>(t1) > get<1>(t2);
            }
            return get<0>(t1) > get<0>(t2);
        }
        return get<2>(t1) > get<2>(t2);
    }
};

// 먹을 수 있는 먹이가 있는지, 갈 수 있는지
bool isPos()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] > 0 && sharkSize > board[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(board, 0, sizeof(board));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            // 아기 상어 포지션 저장
            if (board[i][j] == 9) {
                board[i][j] = 0;
                x = i;
                y = j;
            }
        }
    }

    int need = sharkSize;
    while (isPos()) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> pq;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        pq.push(make_tuple(x, y, 0));
        isVisited[x][y] = true;

        int savAns = answer;
        while (!pq.empty()) {
            int cx = get<0>(pq.top());
            int cy = get<1>(pq.top());
            int time = get<2>(pq.top());
            pq.pop();

            if (board[cx][cy] != 0 && sharkSize > board[cx][cy]) {
                // cout << "move (" << x << ", " << y << ") -> (" << cx << ", " << cy << "), ";
                x = cx;
                y = cy;
                answer += time;
                board[cx][cy] = 0;
                --need;
                if (need == 0) {
                    ++sharkSize;
                    need = sharkSize;
                }
                // cout << "answer : " << answer << ", sharkSize : " << sharkSize << ", need : " << need << '\n';
                break;
            }
            else if (sharkSize < board[cx][cy]) {
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int ccx = cx + dx[i];
                int ccy = cy + dy[i];
                if (ccx < 0 || ccy < 0 || ccx >= n || ccy >= n) continue;
                if (!isVisited[ccx][ccy]) {
                    isVisited[ccx][ccy] = true;
                    pq.push(make_tuple(ccx, ccy, time + 1));
                }
            }
        }
        // 도달할 수 없는 경우
        if (savAns == answer) {
            break;
        }
    }
    cout << answer << '\n';

    return 0;
}