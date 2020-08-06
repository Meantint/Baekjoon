#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 0;
int firstNum = -1;
int arr[101];
bool isCheck[101];

void check(int num, bool thisCase[])
{
    // if (arr[num] == num) {
    //     isCheck[num] = true;
    //     return;
    // }
    if (thisCase[num] == true) {
        if (firstNum == num) {
            for (int i = 1; i < n + 1; ++i) {
                if (thisCase[i] == true) {
                    isCheck[i] = true;
                }
            }
        }
        return;
    }
    thisCase[num] = true;
    check(arr[num], thisCase);
    return;
}

int main()
{
    memset(isCheck, 0, sizeof(isCheck));
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        cin >> arr[i];
    }

    bool tmp[101];
    for (int i = 1; i < n + 1; ++i) {
        memset(tmp, 0, sizeof(tmp));
        firstNum = i;
        check(i, tmp);
    }

    for (int i = 1; i < n + 1; ++i) {
        if (isCheck[i] == true) {
            ++answer;
        }
    }
    cout << answer << '\n';
    for (int i = 1; i < n + 1; ++i) {
        if (isCheck[i] == true) {
            cout << i << '\n';
        }
    }

    return 0;
}