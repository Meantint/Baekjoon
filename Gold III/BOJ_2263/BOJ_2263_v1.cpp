#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in, post;

void DC(int in_low, int in_high, int post_low, int post_high)
{
    if (in_low > in_high) {
        return;
    }
    // cout << "il, ih, pl, ph : " << in_low << ", " << in_high << ", " << post_low << ", " << post_high << ", " << post[post_high] << '\n';
    cout << post[post_high] << ' ';
    if (in_low == in_high) {
        return;
    }

    int target = post[post_high];
    int in_target = -1;
    for (int i = in_low; i <= in_high; ++i) {
        if (in[i] == target) {
            in_target = i;
            break;
        }
    }

    DC(in_low, in_target - 1, post_low, post_low + in_target - in_low - 1);  // left
    DC(in_target + 1, in_high, post_low + in_target - in_low, post_high - 1);
}

int main()
{
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }

    DC(0, n - 1, 0, n - 1);
    cout << '\n';

    return 0;
}