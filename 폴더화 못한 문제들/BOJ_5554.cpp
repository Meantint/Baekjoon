#include <bits/stdc++.h>

using namespace std;

int main()
{
        int num;
        int answer = 0;

        for (int i = 0; i < 4; ++i) {
                cin >> num;
                answer += num;
        }
        cout << answer / 60 << '\n'
             << answer % 60 << '\n';

        return 0;
}