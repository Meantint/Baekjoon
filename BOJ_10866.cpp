#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;

        if (str.substr(0, 2) == "pu") {
            if (str[5] == 'b') {
                cin >> str;
                dq.push_back(stoi(str));
            }
            else {
                cin >> str;
                dq.push_front(stoi(str));
            }
        }
        else if (str.substr(0, 2) == "po") {
            if (str[4] == 'b') {
                if (!dq.empty()) {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
                else {
                    cout << "-1\n";
                }
            }
            else {
                if (!dq.empty()) {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
                else {
                    cout << "-1\n";
                }
            }
        }
        else if (str.substr(0, 2) == "si") {
            cout << dq.size() << '\n';
        }
        else if (str.substr(0, 2) == "em") {
            if (dq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (str.substr(0, 2) == "fr") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        else if (str.substr(0, 2) == "ba") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}