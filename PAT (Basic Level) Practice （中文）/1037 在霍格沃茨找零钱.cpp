#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int P_Galleon, P_Sickle, P_Knut;	// 应付
	int A_Galleon, A_Sickle, A_Knut;    // 实付

	scanf("%d.%d.%d", &P_Galleon, &P_Sickle, &P_Knut);
	scanf("%d.%d.%d", &A_Galleon, &A_Sickle, &A_Knut);

	// 先假设应付的钱少于实付的钱，然后比较大小
	bool P_Flag = false; 
	if (P_Galleon > A_Galleon || (P_Galleon == A_Galleon && P_Sickle > A_Sickle) || (P_Galleon == A_Galleon && P_Sickle == A_Sickle && P_Knut > A_Knut))
		P_Flag = true;
	
	int cut_flag = false; // 用来表示是否需要向上一层借位
	if (!P_Flag)
	{
		if (A_Knut < P_Knut)
		{
			cut_flag = true;
			A_Knut += 29;
		}
		A_Knut -= P_Knut;

		if (cut_flag)
		{
			A_Sickle--;
			cut_flag = false;
		}

		if (A_Sickle < P_Sickle)
		{
			cut_flag = true;
			A_Sickle += 17;
		}
		A_Sickle -= P_Sickle;

		if (cut_flag)
		{
			A_Galleon--;
		}
		A_Galleon -= P_Galleon;
		cout << A_Galleon << "." << A_Sickle << "." << A_Knut;
	}
	else
	{
		if (P_Knut < A_Knut)
		{
			cut_flag = true;
			P_Knut += 29;
		}
		P_Knut -= A_Knut;

		if (cut_flag)
		{
			P_Sickle--;
			cut_flag = false;
		}

		if (P_Sickle < A_Sickle)
		{
			cut_flag = true;
			P_Sickle += 17;
		}
		P_Sickle -= A_Sickle;

		if (cut_flag)
		{
			P_Galleon--;
		}
		P_Galleon -= A_Galleon;

		cout << "-" << P_Galleon << "." << P_Sickle << "." << P_Knut;
	}
	return 0;
}
