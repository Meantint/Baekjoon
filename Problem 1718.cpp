#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	string answer = "";

	char str[30010] = { 0 };
	string key;
	// cin >> str;
	scanf("%[^\n]s", str);	// 개행 입력을 받기 전까지 계속 입력을 받음(공백 포함)
	cin >> key;

	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == ' ') {
			answer.push_back(' ');
			continue;
		}
		if(str[i] > key[i%key.size()])
			answer.push_back(str[i] - key[i % key.size()] + 'a' - 1);
		else
			answer.push_back(str[i] - key[i % key.size()] + 'a' + 25);
	}

	cout << answer << endl;

	return 0;
}
