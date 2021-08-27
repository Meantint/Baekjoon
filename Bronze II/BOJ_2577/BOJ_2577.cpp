#include <iostream>
#include <vector>

using namespace std;

int a, b, c;
vector<int> numCount(10, 0);

int main()
{
    cin >> a >> b >> c;

    int ret = a * b * c;
    while (ret != 0) {
        ++numCount[ret % 10];
        ret /= 10;
    }

    for (int i = 0; i < 10; ++i) {
        cout << numCount[i] << '\n';
    }

    return 0;
}