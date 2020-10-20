#include <iostream>
#include <vector>

#define MAX 4000100

using namespace std;

int n, answer = 0;
vector<bool> isP(MAX, true);
vector<int> pn;

int main()
{
    cin >> n;
    for (int i = 2; i < MAX; ++i) {
        // 소수가 아니라면 continue;
        if (!isP[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            isP[j] = false;
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if (isP[i]) pn.push_back(i);
    }
    int st = 0;
    int ed = 0;
    int val = pn[0];
    int primeSize = pn.size();
    while (st < primeSize && pn[st] <= n) {
        if (val < n) {
            ++ed;
            if (ed == primeSize) break;
            val += pn[ed];
        }
        else if (val == n) {
            ++answer;
            val -= pn[st];
            ++st;
            // st == ed 였던 경우
            if (st > ed) {
                ++ed;
                if (ed == primeSize) break;
                val += pn[ed];
            }
        }
        // val > n
        else {
            val -= pn[st];
            ++st;
            // st == ed 였던 경우
            if (st > ed) {
                ++ed;
                if (ed == primeSize) break;
                val += pn[ed];
            }
        }
    }
    cout << answer << '\n';

    return 0;
}