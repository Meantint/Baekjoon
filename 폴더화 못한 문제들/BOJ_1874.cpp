#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    stack<int> s;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    string str = "";
    int idx = vec.size();
    int maxN = vec.size();
    while (maxN != 0) {
        if (!s.empty() && s.top() == maxN) {
            s.pop();
            str += '-';
            --maxN;
            continue;
        }
        if (vec[--idx] != maxN) {
            s.push(vec[idx]);
            str += '+';
        }
        else {
            s.push(vec[idx]);
            str += '+';
            s.pop();
            str += '-';
            --maxN;
        }
        if (idx == -1 && s.top() != maxN) {
            cout << "NO\n";
            return 0;
        }
    }
    reverse(str.begin(), str.end());
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (str[i] == '+') {
            cout << '-' << '\n';
        }
        else {
            cout << '+' << '\n';
        }
    }

    return 0;
}