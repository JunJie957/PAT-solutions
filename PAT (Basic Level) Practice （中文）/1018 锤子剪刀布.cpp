#include <iostream>
#include <string>
using namespace std;

struct win
{
	int win_count;
	int lose_count;
	int equal_count;
	int win_c;
	int win_j;
	int win_b;

	win(int win, int lose, int equal, int c, int j, int b) 
	:win_count(win),
	lose_count(lose),
	equal_count(equal),
	win_c(c), 
	win_j(j), 
	win_b(b){}
};

int main()
{
	int n;
	cin >> n;

	char a, b;
	win people_a(0, 0, 0, 0, 0, 0);
	win people_b(0, 0, 0, 0, 0, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a == 'C')
		{
			if (b == 'C')
			{
				people_a.equal_count++;
				people_b.equal_count++;
			}
			else if (b == 'J')
			{
				people_a.win_count++;
				people_a.win_c++;
				people_b.lose_count++;
			}
			else if (b == 'B')
			{
				people_a.lose_count++;
				people_b.win_count++;
				people_b.win_b++;
			}
		}
		else if (a == 'J')
		{
			if (b == 'C')
			{
				people_a.lose_count++;
				people_b.win_count++;
				people_b.win_c++;
			}
			else if (b == 'J')
			{
				people_a.equal_count++;
				people_b.equal_count++;
			}
			else if (b == 'B')
			{
				people_a.win_count++;
				people_a.win_j++;
				people_b.lose_count++;
			}
		}
		else if (a == 'B')
		{
			if (b == 'C')
			{
				people_a.win_count++;
				people_a.win_b++;
				people_b.lose_count++;
			}
			else if (b == 'J')
			{
				people_a.lose_count++;
				people_b.win_count++;
				people_b.win_j++;
			}
			else if (b == 'B')
			{
				people_a.equal_count++;
				people_b.equal_count++;
			}
		}
	}

	printf("%d %d %d\n", people_a.win_count, people_a.equal_count, people_a.lose_count);
	printf("%d %d %d\n", people_b.win_count, people_b.equal_count, people_b.lose_count);
	
	if (people_a.win_b >= people_a.win_c)
	{
		if (people_a.win_b >= people_a.win_j) printf("B ");
		else printf("J ");
	}	
	else if (people_a.win_c >= people_a.win_j) printf("C ");
	else printf("J ");
		

	if (people_b.win_b >= people_b.win_c)
	{
		if (people_b.win_b >= people_b.win_j) printf("B");
		else printf("J");
	}
	else if (people_b.win_c >= people_b.win_j) printf("C");
	else printf("J");
		

	return 0;

}
