#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, str_size;
string str;
bool isTwo = false;
vector<int> num_count(10, 0);

string answer = "";

void solve(string cur, int start, int change)
{
    // 이 함수 들어왔을 때 change가 0인 경우 바로 비교 후 리턴
    if (change == 0) {
        if (stoi(answer) < stoi(cur)) {
            answer = cur;
        }

        return;
    }

    for (int i = start; i < str_size; ++i) {
        if (i == str_size - 1 || change == 0) {
            break;
        }
        char max_value = 0;
        int max_count = 0;
        int max_index = -1;

        for (int j = i + 1; j < str_size; ++j) {
            if (max_value < cur[j]) {
                max_value = cur[j];
                max_index = j;
                max_count = 1;
            }
            else if (max_value == cur[j]) {
                ++max_count;
            }
        }

        if (cur[i] >= max_value) {
            continue;
        }

        // 현재 바꾸려는 cur[i]보다 큰 값이 여러개 있다면 모든 경우를 다 탐색해봐야 한다.
        if (max_count > 1) {
            for (int j = i + 1; j < str_size; ++j) {
                if (max_value == cur[j]) {
                    string temp = cur;
                    char ch = temp[j];
                    temp[j] = temp[i];
                    temp[i] = ch;

                    if (change != 0) {
                        solve(temp, i + 1, change - 1);
                    }
                }
            }
        }
        // 현재 바꾸려는 cur[i]보다 큰 값이 1개인 경우 변경해준다.
        else {
            char ch = cur[max_index];
            cur[max_index] = cur[i];
            cur[i] = ch;

            --change;
        }
    }

    // 변경 횟수가 남아 있고 그 값이 홀수이며, 모든 숫자값이 1개 이하로 들어있는 경우
    // 끝 두자리를 바꿔줘야 K번을 소진할 수 있다.
    if (change != 0 && !isTwo && change % 2 != 0) {
        char temp = cur[str_size - 2];
        cur[str_size - 2] = cur[str_size - 1];
        cur[str_size - 1] = temp;
    }

    // change를 0까지 소진하고 난 후 answer와의 비교를 통해 값을 갱신(or not)해준다.
    if (stoi(answer) < stoi(cur)) {
        answer = cur;
    }
}

int main()
{
    cin >> str >> k;
    str_size = str.size();

    // 예외 케이스
    // 1. str 사이즈가 1인 경우
    // 2. str 사이즈가 2이고 끝자리가 0인 경우
    // -1 리턴
    if (str_size == 1 || (str_size == 2 && str.back() == '0')) {
        cout << -1 << '\n';

        return 0;
    }

    // 하나의 숫자 값이라도 2개 이상 있는 경우 K가 몇개가 남았던 현재의 값을 유지할 수 있다.
    for (int i = 0; i < str_size; ++i) {
        ++num_count[str[i] - '0'];
    }
    for (int i = 0; i < 10; ++i) {
        if (num_count[i] >= 2) {
            isTwo = true;
            break;
        }
    }

    // answer 초기화
    if (isTwo || k % 2 == 0) {
        answer = str;
    }
    else {
        string temp = str;
        char ch = temp[str_size - 1];
        temp[str_size - 1] = temp[str_size - 2];
        temp[str_size - 2] = ch;

        answer = temp;
    }

    solve(str, 0, k);

    cout << answer << '\n';

    return 0;
}