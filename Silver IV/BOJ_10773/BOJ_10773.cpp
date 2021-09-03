#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num == 0) {
            if (!s.empty()) {
                s.pop();
            }
        }
        else {
            s.push(num);
        }
    }

    int ret = 0;
    while (!s.empty()) {
        ret += s.top();
        s.pop();
    }

    cout << ret << '\n';

    return 0;
}