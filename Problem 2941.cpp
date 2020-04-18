#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'c') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == '=') {
					cnt++;
					i++;
				}
				else if (str[i + 1] == '-') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		// 잠시 보류
		else if (str[i] == 'd') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == 'z') {
					if (i + 2 < str.size()) {
						if (str[i + 2] == '=') {
							cnt++;
							i += 2;
						}
						else cnt++;
					}
					else cnt++;
				}
				else if (str[i + 1] == '-') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (str[i] == 'l') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == 'j') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (str[i] == 'n') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == 'j') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (str[i] == 's') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == '=') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else if (str[i] == 'z') {
			if (i + 1 < str.size()) {
				if (str[i + 1] == '=') {
					cnt++;
					i++;
				}
				else cnt++;
			}
			else cnt++;
		}
		else {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
