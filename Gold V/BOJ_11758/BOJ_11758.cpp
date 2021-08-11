#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> pos(3);

int ccw(int x1, int x2, int x3, int y1, int y2, int y3)
{
    int temp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

    if (temp > 0) {
        return 1;
    }
    else if (temp == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }

    cout << ccw(pos[0].first, pos[1].first, pos[2].first, pos[0].second, pos[1].second, pos[2].second) << '\n';

    return 0;
}