#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> vec;
    stack<int> sav;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        for (int j = 0; j < num; ++j) {
            sav.push(vec.back());
            vec.pop_back();
        }
        sav.push(i + 1);
        while (!sav.empty()) {
            vec.push_back(sav.top());
            sav.pop();
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << vec[i] << ' ';
    }

    return 0;
}