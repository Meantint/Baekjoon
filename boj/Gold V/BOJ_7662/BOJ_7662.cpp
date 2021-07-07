#include <iostream>
#include <set>

using namespace std;

int t, n, x;
char c;
multiset<int> ms;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        ms.clear();
        cin >> n;
        while (n--) {
            cin >> c >> x;
            if (c == 'I') {
                ms.insert(x);
            }
            else {
                if (x == 1) {
                    // 비어있지 않으면
                    if (!ms.empty()) {
                        ms.erase(--(ms.end()));
                    }
                }
                else {
                    if (!ms.empty()) {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}