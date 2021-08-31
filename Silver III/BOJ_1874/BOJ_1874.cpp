#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> st;
vector<int> info, numList;
vector<char> answer;

int main()
{
    cin >> n;
    info.resize(n);
    numList.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    for (int i = 0; i < n; ++i) {
        numList[i] = i + 1;
    }

    int infoIdx = 0;
    int numListIdx = 1;
    st.push(numList[0]);
    answer.push_back('+');
    while (infoIdx < n) {
        if (st.empty() || st.top() < info[infoIdx]) {
            st.push(numList[numListIdx]);
            ++numListIdx;
            answer.push_back('+');
        }
        else if (st.top() == info[infoIdx]) {
            while (!st.empty() && infoIdx < n && st.top() == info[infoIdx]) {
                st.pop();
                ++infoIdx;
                answer.push_back('-');
            }
        }
        else {
            answer.clear();
            break;
        }
    }

    if (!answer.empty()) {
        int answerSize = answer.size();
        for (int i = 0; i < answerSize; ++i) {
            cout << answer[i] << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}