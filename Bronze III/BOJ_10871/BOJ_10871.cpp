#include <iostream>
#include <vector>

using namespace std;

int n, x;
vector<int> info;

int main()
{
    cin >> n >> x;
    info.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        if (info[i] < x) {
            answer.push_back(info[i]);
        }
    }

    int size = answer.size();
    for (int i = 0; i < size; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}