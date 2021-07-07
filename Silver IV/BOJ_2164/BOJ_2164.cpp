#include <iostream>
#include <vector>

using namespace std;

int n;
int idx = 0, answer = -1;
vector<int> card;

int main()
{
    cin >> n;
    card.resize(n);
    for (int i = 0; i < n; ++i) {
        card[i] = i + 1;
    }
    while (1) {
        // 가장 앞에 있는 숫자가 마지막 숫자가 아니라면 다음 인덱스로 넘어간다.
        if (idx == (int)(card.size() - 1)) {
            answer = card.back();

            break;
        }
        else {
            ++idx;
        }
        // 가장 앞에 있는 숫자를 가장 뒤로 넘겨준다.
        if (idx == (int)(card.size() - 1)) {
            answer = card.back();

            break;
        }
        else {
            card.push_back(card[idx]);
            ++idx;
        }
    }
    cout << answer << '\n';

    return 0;
}