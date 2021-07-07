#include <iostream>

using namespace std;

int n, k;
int answer = 1;

int main()
{
    cin >> n >> k;
    // 나누기 보다 먼저 곱해줘야 쓸데없는 소수점이 생기지 않는다.
    for (int i = 0; i < k; ++i) {
        answer *= (n - i);
    }
    for (int i = 0; i < k; ++i) {
        answer /= (i + 1);
    }
    cout << answer << '\n';

    return 0;
}