// 구현은 집중해서.. 하드코딩 할 일이 많다

#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// [0][0] : R의 x좌표, [0][1] : R의 y좌표
// [1][0] : B의 x좌표, [1][1] : B의 y좌표
int pos[2][2];
int posOx, posOy;
int n, m;
vector<vector<char>> board;

// 'O' 만나면 (-1, -1)
void mov(int cx, int cy, int dir, int color)
{
    // 왼쪽
    if (dir == 0) {
        for (int i = cy; i >= 0; --i) {
            char ch = board[cx][i];
            if (pos[(color + 1) % 2][0] == pos[color][0] && pos[(color + 1) % 2][1] == pos[color][1]) {
                ++pos[color][1];
                break;
            }
            else if (ch == '.') {
                pos[color][1] = i;
            }
            else if (ch == '#') {
                break;
            }
            else if (ch == 'O') {
                pos[color][0] = pos[color][1] = -1;
                break;
            }
        }
    }
    // 오른쪽
    else if (dir == 1) {
        for (int i = cy; i < m; ++i) {
            char ch = board[cx][i];
            if (pos[(color + 1) % 2][0] == pos[color][0] && pos[(color + 1) % 2][1] == pos[color][1]) {
                --pos[color][1];
                break;
            }
            else if (ch == '.') {
                pos[color][1] = i;
            }
            else if (ch == '#') {
                break;
            }
            else if (ch == 'O') {
                pos[color][0] = pos[color][1] = -1;
                break;
            }
        }
    }
    // 위쪽
    else if (dir == 2) {
        for (int i = cx; i >= 0; --i) {
            char ch = board[i][cy];
            if (pos[(color + 1) % 2][0] == pos[color][0] && pos[(color + 1) % 2][1] == pos[color][1]) {
                ++pos[color][0];
                break;
            }
            else if (ch == '.') {
                pos[color][0] = i;
            }
            else if (ch == '#') {
                break;
            }
            else if (ch == 'O') {
                pos[color][0] = pos[color][1] = -1;
                break;
            }
        }
    }
    // 아래쪽
    else {
        for (int i = cx; i < n; ++i) {
            char ch = board[i][cy];
            if (pos[(color + 1) % 2][0] == pos[color][0] && pos[(color + 1) % 2][1] == pos[color][1]) {
                --pos[color][0];
                break;
            }
            else if (ch == '.') {
                pos[color][0] = i;
            }
            else if (ch == '#') {
                break;
            }
            else if (ch == 'O') {
                pos[color][0] = pos[color][1] = -1;
                break;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    board = vector<vector<char>>(n, vector<char>(m, ' '));
    int isVisited[10][10][10][10];
    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                pos[0][0] = i;
                pos[0][1] = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                pos[1][0] = i;
                pos[1][1] = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'O') {
                posOx = i;
                posOy = j;
            }
        }
    }

    int answer = -1;
    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(0, pos[0][0], pos[0][1], pos[1][0], pos[1][1]));
    while (!q.empty()) {
        int dist = get<0>(q.front());
        int cxR = get<1>(q.front());
        int cyR = get<2>(q.front());
        int cxB = get<3>(q.front());
        int cyB = get<4>(q.front());
        q.pop();

        if (isVisited[cxR][cyR][cxB][cyB]) continue;
        pos[0][0] = cxR;
        pos[0][1] = cyR;
        pos[1][0] = cxB;
        pos[1][1] = cyB;
        // cout << "(" << pos[0][0] << ", " << pos[0][1] << ", " << pos[1][0] << ", " << pos[1][1] << ")\n";
        // 왼쪽 우선순위
        if (cyR <= cyB) {
            mov(cxR, cyR, 0, 0);
            // cout << "(" << pos[0][0] << ", " << pos[0][1] << ", " << pos[1][0] << ", " << pos[1][1] << ")\n";
            mov(cxB, cyB, 0, 1);
            // cout << "(" << pos[0][0] << ", " << pos[0][1] << ", " << pos[1][0] << ", " << pos[1][1] << ")\n";
        }
        else {
            mov(cxB, cyB, 0, 1);
            mov(cxR, cyR, 0, 0);
        }
        if (pos[1][0] == -1 && pos[1][1] == -1) {
        }
        else {
            if (pos[0][0] == -1 && pos[0][1] == -1) {
                answer = dist + 1;
                break;
            }
            else {
                if (dist + 1 != 10) {
                    q.push(make_tuple(dist + 1, pos[0][0], pos[0][1], pos[1][0], pos[1][1]));
                }
            }
        }
        pos[0][0] = cxR;
        pos[0][1] = cyR;
        pos[1][0] = cxB;
        pos[1][1] = cyB;
        // 오른쪽 우선순위
        if (cyR >= cyB) {
            mov(cxR, cyR, 1, 0);
            mov(cxB, cyB, 1, 1);
        }
        else {
            mov(cxB, cyB, 1, 1);
            mov(cxR, cyR, 1, 0);
        }
        if (pos[1][0] == -1 && pos[1][1] == -1) {
        }
        else {
            if (pos[0][0] == -1 && pos[0][1] == -1) {
                answer = dist + 1;
                break;
            }
            else {
                if (dist + 1 != 10) {
                    q.push(make_tuple(dist + 1, pos[0][0], pos[0][1], pos[1][0], pos[1][1]));
                }
            }
        }
        pos[0][0] = cxR;
        pos[0][1] = cyR;
        pos[1][0] = cxB;
        pos[1][1] = cyB;
        // 위쪽 우선순위
        if (cxR <= cxB) {
            mov(cxR, cyR, 2, 0);
            mov(cxB, cyB, 2, 1);
        }
        else {
            mov(cxB, cyB, 2, 1);
            mov(cxR, cyR, 2, 0);
        }
        if (pos[1][0] == -1 && pos[1][1] == -1) {
        }
        else {
            if (pos[0][0] == -1 && pos[0][1] == -1) {
                answer = dist + 1;
                break;
            }
            else {
                if (dist + 1 != 10) {
                    q.push(make_tuple(dist + 1, pos[0][0], pos[0][1], pos[1][0], pos[1][1]));
                }
            }
        }
        pos[0][0] = cxR;
        pos[0][1] = cyR;
        pos[1][0] = cxB;
        pos[1][1] = cyB;
        // 아래쪽 우선순위
        if (cxR >= cxB) {
            mov(cxR, cyR, 3, 0);
            mov(cxB, cyB, 3, 1);
        }
        else {
            mov(cxB, cyB, 3, 1);
            mov(cxR, cyR, 3, 0);
        }
        if (pos[1][0] == -1 && pos[1][1] == -1) {
        }
        else {
            if (pos[0][0] == -1 && pos[0][1] == -1) {
                answer = dist + 1;
                break;
            }
            else {
                if (dist + 1 != 10) {
                    q.push(make_tuple(dist + 1, pos[0][0], pos[0][1], pos[1][0], pos[1][1]));
                }
            }
        }
        isVisited[cxR][cyR][cxB][cyB] = true;
    }
    cout << answer << '\n';

    return 0;
}