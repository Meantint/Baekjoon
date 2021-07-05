#include <iostream>
#define MAX 40

using namespace std;

long int cnt_0[MAX + 1];		// 0 ~ 40까지의 0의 개수를 받기 위한 배열
long int cnt_1[MAX + 1];		// 0 ~ 40까지의 1의 개수를 받기 위한 배열

int main(void)
{
	int T;
	cin >> T;

	cnt_0[0] = 1, cnt_1[0] = 0;
	cnt_0[1] = 0, cnt_1[1] = 1;

	for (int i = 2; i < MAX + 1; i++) {		// 피보나치 0번 부터 40번까지의 0, 1 호출 횟수를 기록한다.
		cnt_0[i] = cnt_0[i - 1] + cnt_0[i - 2];
		cnt_1[i] = cnt_1[i - 1] + cnt_1[i - 2];
	}

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;

		cout << cnt_0[num] << " " << cnt_1[num] << endl;
	}
	return 0;
}
