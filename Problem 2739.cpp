#include <stdio.h>

int main(void)
{
	int num = 0;
	int i;

	do {
		scanf("%d", &num);
	} while (num < 1 || num > 9);	// num이 1에서 9사이의 숫자가 아니라면 다시 입력받음

	for (i = 1; i < 10; i++)
		printf("%d * %d = %d\n", num, i, num*i);

	return 0;
}
