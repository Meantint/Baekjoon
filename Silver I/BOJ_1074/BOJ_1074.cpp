#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, r, c, answer = 0;

void solve(int x, int y, int size)
{
    if (x == r && y == c) {
        return;
    }
    int half = size / 2;
    if (r < x + half) {
        if (c < y + half) {
            solve(x, y, half);
        }
        else {
            answer += half * half;
            solve(x, y + half, half);
        }
    }
    else {
        if (c < y + half) {
            answer += half * half * 2;
            solve(x + half, y, half);
        }
        else {
            answer += half * half * 3;
            solve(x + half, y + half, half);
        }
    }
}

int main()
{
    cin >> n >> r >> c;
    solve(0, 0, pow(2, n));
    cout << answer << '\n';

    return 0;
}