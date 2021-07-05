#include <cstdio>

using namespace std;

int main()
{
	int n;
	int kim, im;
	scanf("%d %d %d", &n, &kim, &im);

	int round = 0;
	while (kim != im) {
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
		round++;
	}
	printf("%d \n", round);

	return 0;
}
