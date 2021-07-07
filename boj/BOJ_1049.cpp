#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    vector<PII> vec;
    int minVal_1 = INT_MAX;
    int minVal_2 = INT_MAX;
    for (int i = 0; i < m; ++i) {
        int num1, num2;
        cin >> num1 >> num2;

        vec.push_back(make_pair(num1, num2));
        minVal_1 = min({ minVal_1, num1 * (n / 6), num2 * (n / 6) * 6 });
        minVal_2 = min({ minVal_2, num1, num2 * (n % 6) });
    }
    cout << minVal_1 + minVal_2 << '\n';

    return 0;
}