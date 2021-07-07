#include <algorithm>
#include <iostream>

using namespace std;

int x, y, w, h;
int answer;

int main()
{
    cin >> x >> y >> w >> h;
    answer = min((2 * x > w) ? (w - x) : x, (2 * y > h) ? (h - y) : y);
    cout << answer << '\n';

    return 0;
}