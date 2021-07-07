#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

vector<int> num(9);

// (max_value, idx)
PII answer = make_pair(-1, -1);

int main()
{
    for (auto& n : num) {
        cin >> n;
    }
    for (auto& n : num) {
        if (answer.first < n) {
            answer.first = n;
            answer.second = (&n - &num[0] + 1);
        }
    }
    cout << answer.first << '\n'
         << answer.second << '\n';

    return 0;
}