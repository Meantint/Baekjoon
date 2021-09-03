#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> info(3);

int main()
{
    while (1) {
        cin >> info[0] >> info[1] >> info[2];
        if (info[0] == 0 && info[1] == 0 && info[2] == 0) {
            break;
        }

        sort(info.begin(), info.end());  // 오름차순 정렬
        if (pow(info[0], 2) + pow(info[1], 2) == pow(info[2], 2)) {
            cout << "right" << '\n';
        }
        else {
            cout << "wrong" << '\n';
        }
    }

    return 0;
}