#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> angle(3);

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> angle[i];
    }

    sort(angle.begin(), angle.end());

    if (angle[0] + angle[1] + angle[2] != 180) {
        cout << "Error" << '\n';
    }
    else if (angle[0] == angle[1] && angle[1] && angle[2]) {
        cout << "Equilateral" << '\n';
    }
    else if (angle[0] != angle[1] && angle[1] != angle[2]) {
        cout << "Scalene" << '\n';
    }
    else {
        cout << "Isosceles" << '\n';
    }

    return 0;
}