#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int case_num = 1;
int tc = 0;
int num, change;
bool isSame = false;  // 같은 숫자가 존재하는지의 여부
vector<int> num_list;

int solve(string s, int cnt)
{
    if (cnt == 0) {
        return stoi(s);
    }
    // 제한 함수 내에서의 답
    int answer = 0;

    for (int i = 0; i < s.size(); ++i) {
        char max_val = s[i];
        // i(인덱스) 보다 큰 인덱스 값 중 가장 큰 값을 갱신해준다.
        for (int j = i + 1; j < s.size(); ++j) {
            if (max_val < s[j]) {
                max_val = s[j];
            }
        }
        // 가장 큰 숫자가 맨 앞에 있다면 맨 앞의 숫자를 바꿀 필요 X
        if (max_val == s[i]) {
            continue;
        }
        else {
            for (int j = i + 1; j < s.size(); ++j) {
                if (max_val == s[j]) {
                    string cp = s;
                    swap(cp[i], cp[j]);
                    answer = max(answer, solve(cp, cnt - 1));
                }
            }
            break;
        }
    }
    // 숫자가 내림차순으로 정렬이 완료된 경우
    if (answer == 0) {
        // 남은 횟수가 짝수라면
        if (cnt % 2 == 0) {
            return stoi(s);
        }
        // 남은 횟수가 홀수라면
        else {
            // 하나라도 같은 숫자가 있으면 남은 횟수의 의미가 없다
            if (isSame) {
            }
            else {
                swap(s[s.size() - 2], s[s.size() - 1]);
            }
            return stoi(s);
        }
    }

    return answer;
}

int main()
{
    cin >> tc;
    while (tc--) {
        cin >> num >> change;
        // cout << num << ' ' << change << '\n';
        // if (num / 10 == 0) {
        //     cout << '#' << case_num++ << ' ' << num << '\n';
        //     continue;
        // }
        string sv = to_string(num);
        for (int i = 0; i < sv.size(); ++i) {
            for (int j = i + 1; j < sv.size(); ++j) {
                // 하나라도 같은 숫자가 있으면
                if (sv[i] == sv[j]) {
                    isSame = true;
                }
            }
        }

        cout << '#' << case_num++ << ' ' << solve(sv, change) << '\n';
        isSame = false;
    }

    return 0;
}