#include <iostream>

using namespace std;

int n;
int answer = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp % 5 == 0) {
            ++answer;
            temp /= 5;
        }
    }
    cout << answer << '\n';

    return 0;
}