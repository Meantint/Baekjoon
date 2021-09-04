#include <iostream>
#include <vector>

using namespace std;

int tc, n, m, x, y;
vector<bool> isVisited;

int main()
{
    cin >> tc;
    while (tc--) {
        int ret = 0, target;
        cin >> n >> m >> x >> y;
        isVisited.clear();
        isVisited.resize(m + 1, false);

        // base setting
        ret = target = x;
        target %= m;
        if (target == 0) {
            target = m;
        }

        while (1) {
            if (target == y) {  // answer
                break;
            }

            ret += n;
            target += n;
            target %= m;
            if (target == 0) {
                target = m;
            }
            if (isVisited[target]) {
                ret = -1;
                break;
            }
            isVisited[target] = true;
        }
        cout << ret << '\n';
    }

    return 0;
}