#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int h, w;
vector<int> board;

int main()
{
    cin >> h >> w;
    board = vector<int>(w);
    for (int i = 0; i < w; ++i) {
        cin >> board[i];
    }

    // left, mid, right
    int l = 0, c, r = 1;
    // 초기값 설정
    while (l + 1 < w && board[l + 1] >= board[l]) {
        ++l;
    }
    while (1) {
        while (c + 1 < w && board[c + 1] < board[c]) {
            ++c;
        }
        r = c;
        while (r + 1 < w && board[r + 1] >= board[r]) {
            ++r;
        }
        int hei = min(board[l], board[r]);
        for (int i = l; i <= r; ++i) {
            if (hei > board[i]) {
                answer += (hei - board[i]);
                board[i] = hei;
            }
        }
        if (r == w - 1) break;
        if (board[l] < board[r]) {
            l = r;
            c = l;
        }
        else {
            c = r;  
        }
    }
    cout << answer << '\n';

    return 0;
}