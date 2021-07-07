#include <iostream>

using namespace std;

int n, k, answer = -1;
int board[1001][4];

int rowix[1001];

// 내림차순 해야함
bool sort(int arr1[], int arr2[])
{
    if (arr1[1] < arr2[1]) {
        return 1;
    }
    else if (arr1[1] == arr2[1]) {
        if (arr1[2] < arr2[2]) {
            return 1;
        }
        else if (arr1[2] == arr2[2]) {
            if (arr1[3] < arr2[3]) {
                return 1;
            }
        }
    }

    return 0;
}

void solve()
{
    // 정렬
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sort(board[rowix[i]], board[rowix[j]])) {
                int tmp = rowix[i];
                rowix[i] = rowix[j];
                rowix[j] = tmp;
            }
        }
    }

    int rank = 1;
    int equal = 1;
    int prev[4] = {board[rowix[0]][0], board[rowix[0]][1], board[rowix[0]][2], board[rowix[0]][3]};
    if (prev[0] == k) {
        answer = rank;
        return;
    }
    for (int i = 1; i < n; ++i) {
        bool isSame = true;
        for (int j = 1; j < 4; ++j) {
            if (prev[j] != board[rowix[i]][j]) {
                isSame = false;
                break;
            }
        }
        // 이전의 값과 다르다면 rank를 1증가시킨 후 prev 값 갱신
        if (!isSame) {
            rank += equal;
            equal = 1;

            for (int j = 0; j < 4; ++j) {
                prev[j] = board[rowix[i]][j];
            }
        }
        // 같다면 equal 증가시킨다.
        else {
            prev[0] = board[rowix[i]][0];
            ++equal;
        }
        // 찾는 국가라면
        if (prev[0] == k) {
            // cout << "K : " << k << '\n';
            answer = rank;
            break;
        }
    }

    return;
}

int main()
{
    // indirect array
    for (int i = 0; i < 1001; ++i) {
        rowix[i] = i;
    }
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> board[i][j];
        }
    }
    solve();

    cout << answer << '\n';

    return 0;
}