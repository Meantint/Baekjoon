#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str, str2;
		cin >> str;
		if (str == "push") {	// string은 스페이스를 입력받으면 문자열 하나를 입력받았다고 생각하여 종료한다.
			cin >> str2;
		}

		if (str == "top") {
			if (!s.empty())
				cout << s.top() << endl;
			else
				cout << "-1" << endl;
		}
		else if (str == "pop") {
			if (s.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << endl;
		}
		else if (str == "empty") {
			cout << s.empty() << endl;
		}
		else {
			s.push(stoi(str2));
		}
	}
}
