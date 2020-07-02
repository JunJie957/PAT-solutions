#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	
	char id_number[16] = { 0 };
	char sign_in_time[9] = { 0 };
	char sign_out_time[9] = { 0 };

	char sign_in_earlier[9] = { "23:59:59" }; // 最早到达时间
	char sign_out_last[9] = { "00:00:00" };   // 最晚离开时间

	char id_number_earlier[16] = { 0 };
	char id_number_last[16] = { 0 };

	for (int i = 0; i < m; ++i)
	{
		scanf("%s %s %s", id_number, sign_in_time, sign_out_time);
		
		if(memcmp(sign_in_time, sign_in_earlier, 9) < 0)
		{
			memcpy(sign_in_earlier, sign_in_time, 9);
			memcpy(id_number_earlier, id_number, 16);
		}

		if (memcmp(sign_out_time, sign_out_last, 9) > 0)
		{
			memcpy(sign_out_last, sign_out_time, 9);
			memcpy(id_number_last, id_number, 16);
		}
	}
	printf("%s %s", id_number_earlier, id_number_last);
	return 0;
}
