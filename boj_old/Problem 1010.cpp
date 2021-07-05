#include <iostream>
#include <vector>

#define MAX 30

using namespace std;

// factorial 함수를 만들어서 연산하면 Combination(15, 30)의 
// 연산 값이 제대로 나오지 않는데 너무 큰 수여서 그런 듯
//unsigned long long int factorial(int num, int stop)
//{
//	if (num == 1 || num == stop)		
//		return 1;
//	return num * factorial(num - 1, stop);
//}
//
//int main(void)
//{
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		int n, m;
//		unsigned long long int numberCase;
//		cin >> n >> m;
//
//		if (m - n > n)
//			numberCase = factorial(m, m - n) / factorial(n, 0);
//		else if (m - n == n)
//			numberCase = factorial(m, n) / factorial(n, 0);
//		else
//			numberCase = factorial(m, n) / factorial(m - n, 0);
//
//		cout << numberCase << endl;
//	}
//	
//	return 0;
//}

// 파스칼 삼각형을 이용하여 문제를 해결해야 함.
int main(void)
{
	vector<vector<int>> pascalTriangle(MAX + 1, vector<int>(MAX + 1));	// 동적으로 (30, 30) 배열 생성

	for (int i = 0; i < MAX + 1; i++) {					// 0C0부터 30C30까지 파스칼 삼각형 생성
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)					// 양 끝부분이라면
				pascalTriangle[i][j] = 1;
			else if (j <= i / 2) {					// 가운데를 포함한 가운데에서 왼쪽 부분이라면
				pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
			}
			else							// 나머지 부분이라면(가운데에서 오른쪽 부분)
				pascalTriangle[i][j] = pascalTriangle[i][i - j];
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int m, n;
		cin >> n >> m;

		cout << pascalTriangle[m][n] << endl;
	}

	return 0;
}
