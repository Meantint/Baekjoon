#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string str;
int n;

int main()
{
    cin >> str >> n;
    reverse(str.begin(), str.end());

    int answer = 0;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            answer += (str[i] - 'A' + 10) * pow(n, i);
        }
        else {
            answer += (str[i] - '0') * pow(n, i);
        }
    }

    cout << answer << '\n';

    return 0;
}