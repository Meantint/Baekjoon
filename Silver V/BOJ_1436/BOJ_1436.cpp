#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int answer = 0;

int main()
{
    cin >> n;

    int num = 1;
    int count = 0;
    while (n != count) {
        if (to_string(num).find("666") != string::npos) {
            ++count;
            answer = num;
        }
        ++num;
    }

    cout << answer << '\n';

    return 0;
}