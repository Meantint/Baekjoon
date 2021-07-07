#include <iostream>
#include <stack>

using namespace std;

int n, num;
string str;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        // 공백까지 입력받기 위해서
        cin >> str;
        if (str == "pop") {
            // 비어있다면 -1 출력
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            // 비어있지 않다면 st.top()을 출력 후 삭제
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (str == "size") {
            cout << st.size() << '\n';
        }
        else if (str == "empty") {
            if (st.empty()) {
                cout << '1' << '\n';
            }
            else {
                cout << '0' << '\n';
            }
        }
        else if (str == "top") {
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
        // str == "push"
        else {
            // X
            cin >> num;
            st.push(num);
        }
    }

    return 0;
}