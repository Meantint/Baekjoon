#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(3);

int main()
{
    // 3개의 값 받음
    for (auto& num : v) {
        cin >> num;
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 3개의 수가 연속될 때
    if (v[2] - v[1] == v[1] - v[0]) {
        cout << v[2] + (v[1] - v[0]) << '\n';
    }
    // 오름차순 한 4개의 수 중 (2 or 3)번째 칸이 비어있는 경우
    else {
        cout << (v[2] + v[0]) - v[1] << '\n';
    }

    return 0;
}