#include <iostream>
#include <string>

using namespace std;

string n;

int main()
{
    cin >> n;

    int answer = 0;
    for (int i = 0; i < n.size(); ++i) {
        answer *= 16;
        if ('0' <= n[i] && n[i] <= '9') {
            answer += (n[i] - '0');
        }
        else {
            answer += (n[i] - 'A' + 10);
        }
    }
    cout << answer << '\n';

    return 0;
}