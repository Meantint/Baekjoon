#include <iostream>
#include <vector>

using namespace std;

vector<int> v(5);
int answer = 0;

int main()
{
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    for (auto &num : v) {
        answer += (num * num);
    }
    answer %= 10;
    cout << answer << '\n';

    return 0;
}