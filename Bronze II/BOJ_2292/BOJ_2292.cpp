#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    // 현재 둘러싸고 있는 테두리의 최솟값 low, 최댓값 high
    int low = 1, high = 1;
    int count = 1;
    while (high < n || n < low) {
        low = high + 1;
        high += (6 * count);
        ++count;
    }

    cout << count << '\n';

    return 0;
}