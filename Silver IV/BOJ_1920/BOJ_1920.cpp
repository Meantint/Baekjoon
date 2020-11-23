#include <iostream>
#include <map>

using namespace std;

int n, m;
int num;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        mp[num] = i;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> num;
        // num 숫자가 mp 안에 존재한다면
        if (mp.find(num) != mp.end()) {
            cout << '1' << '\n';
        }
        // 존재하지 않는다면
        else {
            cout << '0' << '\n';
        }
    }

    return 0;
}