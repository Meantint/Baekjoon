#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
vector<PII> point;

bool comp(const PII& p1, const PII& p2)
{
    // p1과 p2의 x좌표가 같다면
    if (p1.first == p2.first) {
        // p1과 p2의 y좌표를 기준으로 오름차순 정렬해준다.
        return p1.second < p2.second;
    }
    // p1과 p2의 x좌표가 같지 않다면 x좌표를 기준으로 오름차순 정렬해준다.
    return p1.first < p2.first;
}

int main()
{
    cin >> n;
    point.resize(n);
    for (auto& p : point) {
        cin >> p.first >> p.second;
    }
    sort(point.begin(), point.end(), comp);
    for (auto& p : point) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}