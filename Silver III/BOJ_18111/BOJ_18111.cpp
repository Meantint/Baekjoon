#include <iostream>
#include <vector>

using namespace std;

int n, m, b;
vector<vector<int>> board;

vector<int> AS()
{
    vector<int> ans = {2112345678, 0};

    int allBlock = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            allBlock += board[r][c];
        }
    }
    allBlock += b;

    for (int i = 0; i <= 256; ++i) {
        int ret = 0;

        if (allBlock < i * n * m) {  // 블록 개수가 모자라면
            break;
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int temp = i - board[r][c];
                if (temp >= 0) {  // 블록을 추가하는 경우
                    ret += temp;
                }
                else {
                    ret += temp * -2;
                }
            }
        }
        if (ans[0] >= ret) {
            ans[0] = ret;
            ans[1] = i;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m >> b;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    vector<int> answer = AS();
    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}