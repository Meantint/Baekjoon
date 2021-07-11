#include <bits/stdc++.h>

using namespace std;

int main()
{
        int num;
        int answer = 0;

        for (int i = 0; i < 5; ++i) {
                cin >> num;
                answer += num;
        }
        cout << answer << '\n';

        return 0;
}