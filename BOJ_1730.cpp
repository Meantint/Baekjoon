#include <bits/stdc++.h>

using namespace std;

int n;
int board[100][100];

int main()
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        cin >> n;
        memset(board, 0, sizeof(board));

        string str;
        cin >> str;

        int i = 0, j = 0;
        int size = str.size();
        for (int k = 0; k < size; ++k) {
                if (str[k] == 'L') {
                        if (j - 1 < 0)
                                continue;
                        else {
                                board[i][j] |= (1 << 1);
                                --j;
                                board[i][j] |= (1 << 1);
                        }
                }
                else if (str[k] == 'R') {
                        if (j + 1 >= n)
                                continue;
                        else {
                                board[i][j] |= (1 << 1);
                                ++j;
                                board[i][j] |= (1 << 1);
                        }
                }
                else if (str[k] == 'D') {
                        if (i + 1 >= n)
                                continue;
                        else {
                                board[i][j] |= (1 << 0);
                                ++i;
                                board[i][j] |= (1 << 0);
                        }
                }
                else {
                        if (i - 1 < 0)
                                continue;
                        else {
                                board[i][j] |= (1 << 0);
                                --i;
                                board[i][j] |= (1 << 0);
                        }
                }
        }
        char answer[n][n];
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (board[i][j] == 0)
                                answer[i][j] = '.';
                        else if (board[i][j] == 1)
                                answer[i][j] = '|';
                        else if (board[i][j] == 2)
                                answer[i][j] = '-';
                        else
                                answer[i][j] = '+';
                        cout << answer[i][j];
                }
                cout << '\n';
        }

        return 0;
}
