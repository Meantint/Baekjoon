#include <stdio.h>

int main(void)
{
	int nCount;
	int a, b;
	scanf("%d", &nCount);
	for (int itr = 0; itr < nCount; itr++)
	{
		scanf("%d %d", &a, &b);
		printf("%d \n", a + b);
	}

	return 0;
}
