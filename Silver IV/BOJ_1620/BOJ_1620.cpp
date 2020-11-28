#include <iostream>
#include <map>

using namespace std;

int n, m;
int idx = 1;
string name;
map<string, int> pok;
map<int, string> pok_idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        cin >> name;
        pok[name] = idx;
        pok_idx[idx] = name;
        ++idx;
    }
    while (m--) {
        cin >> name;
        // 숫자일 경우
        if (name[0] >= '0' && name[0] <= '9') {
            cout << pok_idx[stoi(name)] << '\n';
        }
        // 이름일 경우
        else {
            cout << pok[name] << '\n';
        }
    }

    return 0;
}