#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> info(10001, 0);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        ++info[num];
    }
    for (int i = 1; i < 10001; ++i) {
        for (int j = 0; j < info[i]; ++j) {
            cout << i << '\n';
        }
    }

    return 0;
}