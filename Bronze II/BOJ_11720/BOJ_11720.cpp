#include <iostream>
#include <string>

using namespace std;

int n, answer = 0;
string str;

int main()
{
    cin >> n >> str;
    for (auto& num : str) {
        answer += (num - '0');
    }
    cout << answer << '\n';

    return 0;
}