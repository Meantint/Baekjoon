#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int n;
int age;
string name;
vector<tuple<int, string, int>> mem;

bool comp(const tuple<int, string, int>& t1, const tuple<int, string, int>& t2)
{
    // 나이가 똑같은 경우
    if (get<0>(t1) == get<0>(t2)) {
        // 가입한 순으로 정렬해준다.
        return get<2>(t1) < get<2>(t2);
    }
    // 나이가 다르다면 나이순으로 오름차순 정렬해준다.
    return get<0>(t1) < get<0>(t2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> age >> name;
        mem.push_back(make_tuple(age, name, i));
    }
    sort(mem.begin(), mem.end(), comp);
    for (auto& m : mem) {
        cout << get<0>(m) << ' ' << get<1>(m) << '\n';
    }

    return 0;
}