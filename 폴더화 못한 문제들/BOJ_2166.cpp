// 벡터의 외적을 이용하면 다각형의 넓이를 구할 수 있다.
// 근데 더 배울일이 있으려나..?

#include <cmath>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
vector<PII> point;
PII fixPoint;

int main()
{
    cin >> n;
    point = vector<PII>(n);
    for (int i = 0; i < n; ++i) {
        cin >> point[i].first >> point[i].second;
    }
    fixPoint = make_pair(point[0].first, point[0].second);
    long long answer = 0;
    bool dec = false;
    for (int i = 1; i < n - 1; ++i) {
        long long sum = (long long)(point[i].first - fixPoint.first) * (point[i + 1].second - fixPoint.second) -
                        (long long)(point[i + 1].first - fixPoint.first) * (point[i].second - fixPoint.second);
        answer += sum;
    }
    double ans = (double)answer / (double)2;
    cout << fixed;
    cout.precision(1);
    if (answer < 0) {
        cout << -ans << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}