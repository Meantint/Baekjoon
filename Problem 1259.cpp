#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;
	while (1) {
		string str;
		cin >> str;

		if (str == "0") {
			break;
		}

		for (i = 0; i < str.size() / 2; i++) {
			if (str[i] != str[str.size() - i - 1]) {
				cout << "no" << endl;
				break;
			}
		}
		if (i == str.size() / 2)
			cout << "yes" << endl;
	}

	return 0;
}
