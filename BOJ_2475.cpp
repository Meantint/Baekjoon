#include <bits/stdc++.h>

using namespace std;

int main()
{
        vector<int> vec;
        for (int i = 0; i < 5; ++i) {
                int num;
                cin >> num;
                vec.push_back(num);
        }

        int answer = 0;
        for (int i = 0; i < 5; ++i) {
                answer += pow(vec[i], 2);
        }
        cout << answer % 10 << '\n';

        return 0;
}