#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int total, k;
	scanf("%d %d", &total, &k);

	int n1, b, t, n2;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d %d %d %d", &n1, &b, &t, &n2);

		if (total == 0)
		{
			printf("Game Over.");
			break;
		}

		if (t > total)
		{
			printf("Not enough tokens.  Total = %d.", total);
		}
		else if ((b == 0 && n2 < n1) || (b == 1 && n2 > n1))
		{
			total += t;
			printf("Win %d!  Total = %d.", t, total);
		}
		else
		{
			total -= t;
			printf("Lose %d.  Total = %d.", t, total);
		}
		if (i != k - 1) printf("\n");
	}
	return 0;
}
