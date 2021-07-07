#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
int num;
vector<bool> isPrime(1001, true);
vector<int> prime;

int main()
{
    for (int i = 2; i < 1001; ++i) {
        // i가 소수가 아니라면 continue
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * 2; j < 1001; j += i) {
            isPrime[j] = false;
        }
        // 여기까지 왔으면 i는 무조건 소수기 때문에 prime에 넣어준다.
        prime.push_back(i);
    }
    cin >> n;
    while (n--) {
        cin >> num;
        for (auto& p : prime) {
            if (p < num) {
                continue;
            }
            else if (p > num) {
                break;
            }
            else {
                ++answer;
                break;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}