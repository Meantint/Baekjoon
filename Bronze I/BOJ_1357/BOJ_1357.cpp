#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string x, y;

int main()
{
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    string answer = to_string(stoi(x) + stoi(y));
    reverse(answer.begin(), answer.end());

    cout << stoi(answer) << '\n';

    return 0;
}