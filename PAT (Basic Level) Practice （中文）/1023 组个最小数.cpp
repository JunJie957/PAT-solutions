#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// scanf()��printf()������Ч�ʱ�cin��cout��һЩ��ͨ���ύͨ����ʱ���¼�ж� 

int main()
{
	int number[10] = { 0 };
	bool flag = true;
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &number[i]);
		if (flag && number[i] > 0 && i != 0)
		{
			printf("%d", i);	// �����λ��Ϊ�������
			--number[i];
			flag = false;
		}
	}

	// ����������С�����˳������������е�����
	for (int i = 0; i < 10; ++i)
	{
		while (number[i] > 0)
		{
			printf("%d", i);
			--number[i];
		}
	}
	return 0;
}
