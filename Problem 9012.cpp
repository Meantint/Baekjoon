#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string test = "";
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++) {
			if (test.size() == 0) {
				if (str[j] == '(') {
					test.push_back('(');
				}
				else {
					test.push_back('0');
					break;
				}
			}
			else if (test.back() == '(') {
				if (str[j] == '(')
					test.push_back('(');
				else {
					test.pop_back();
				}
			}
		}
		if (test[0] == '0') {
			cout << "NO" << endl;
		}
		else if(test.size() == 0)
			cout << "YES" << endl;
		else {
			cout << "NO" << endl;
		}
		test = "";
	}


	return 0;
}
