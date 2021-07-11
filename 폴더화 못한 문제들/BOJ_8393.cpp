#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n;
        int answer = 0;

        cin >> n;
        for (int i = 1; i < n + 1; ++i) {
                answer += i;
        }
        cout << answer << '\n';

        return 0;
}