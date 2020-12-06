#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, answer = 0;
// vector<int> point(15);
int point[15];

bool isCheck(int cur)
{
    for (int i = 0; i < cur; ++i) {
        if (point[cur] == point[i] || cur - i == abs(point[cur] - point[i])) {
            return false;
        }
    }

    return true;
}

void nQueen(int cur)
{
    if (cur == n) {
        ++answer;
    }
    else {
        for (int i = 0; i < n; ++i) {
            point[cur] = i;
            if (isCheck(cur)) {
                nQueen(cur + 1);
            }
        }
    }
}

int main()
{
    cin >> n;

    nQueen(0);

    cout << answer << '\n';

    return 0;
}