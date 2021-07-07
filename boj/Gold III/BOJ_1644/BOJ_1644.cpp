#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<bool> isPrime(4000001, true);
vector<int> prime;

int main()
{
    cin >> n;
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < 4000001; ++i) {
        // i가 소수가 아니라면 넘어간다.
        if (!isPrime[i]) continue;

        for (int j = i * 2; j < 4000001; j += i) {
            isPrime[j] = false;
        }
        // 여기까지 온 i는 무조건 소수이기 때문에 prime에 추가한다.
        prime.push_back(i);
    }

    // 투 포인터, cur: st ~ ed 구간의 합
    int st, ed, cur;
    int pSize = prime.size();
    st = ed = 0;
    cur = prime[0];

    while (1) {
        // 투 포인터의 끝부분이 찾는 값 보다 크다면 더 찾을 필요 없다.
        if (ed >= pSize || prime[ed] > n) {
            break;
        }
        // 찾는 값 보다 작다면 끝부분을 늘려준다.
        if (cur < n) {
            ++ed;
            cur += prime[ed];
        }
        // 찾는 값 보다 크다면 앞부분을 줄여준다.
        else if (cur > n) {
            cur -= prime[st];
            ++st;
        }
        // 찾는 값과 같다면
        else {
            ++answer;
            ++ed;
            cur += prime[ed];
        }
    }
    cout << answer << '\n';

    return 0;
}