#include <bits/stdc++.h>

using namespace std;

int Answer;
int n;

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;

        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        vector<int> cp = vec;
        for (int i = 0; i < n; ++i) {
            cp[n - 1 - i] += (i + 1);
        }
        sort(cp.begin(), cp.end());
        int idx = n - 1;
        while (idx >= 0 && vec[idx] + n >= cp.back()) {
            --idx;
        }
        Answer = n - idx - 1;

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}