// Multiset 사용
// Multiset은 set 헤더 필요, map과 유사한 STL Library

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int t, tt;

int main()
{
    cin >> t;
    while (t--) {
        cin >> tt;

        multiset<int> ms;
        while (tt--) {
            char ch;
            int num;
            cin >> ch >> num;

            if (ch == 'I') {
                ms.insert(num);
            }
            else {
                if (!ms.empty()) {
                    if (num == 1) {
                        set<int>::iterator it = ms.end();
                        --it;
                        ms.erase(it);
                    }
                    else {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}