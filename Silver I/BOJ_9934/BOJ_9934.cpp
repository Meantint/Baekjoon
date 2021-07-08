#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
int real_size;
vector<int> order;
vector<vector<int>> answer;

void middle(int start, int end, int depth)
{
    // cout << start << ", " << end << ", " << depth << '\n';
    int mid = (start + end) / 2;
    answer[depth].push_back(order[mid]);

    if (start == end) {
        return;
    }

    middle(start, mid - 1, depth + 1);
    middle(mid + 1, end, depth + 1);

    return;
}

int main()
{
    cin >> n;

    real_size = pow(2, n);
    answer.resize(n);
    order.resize(real_size, 0);

    for (int i = 0; i < real_size; ++i) {
        cin >> order[i];
    }

    middle(0, real_size - 2, 0);

    for (int i = 0; i < n; ++i) {
        int size = answer[i].size();
        for (int j = 0; j < size; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}