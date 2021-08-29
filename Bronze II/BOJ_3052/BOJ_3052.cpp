#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> answer;

int main()
{
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        answer.push_back(num % 42);
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    cout << answer.size() << '\n';

    return 0;
}