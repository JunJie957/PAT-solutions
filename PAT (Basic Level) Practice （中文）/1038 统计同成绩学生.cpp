#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ��scanf()��printf()�滻Ϊcin��cout���ᷢ���г�ʱ����
// ��ˣ����㷨��Ŀ�о���ʹ��scanf()��printf()����������Ҫ������������ʱ��

int arr[10000] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	int score;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &score);
		arr[score]++;
	}

	int look;
	scanf("%d", &look);
	for (int i = 0; i < look; ++i)
	{
		//cin >> score;  // ʹ��cinʱ���ύ�𰸻���ֳ�ʱ���󣬿��Դ���һ��
		scanf("%d", &score);
		if (i != look - 1) printf("%d ", arr[score]);
		else  printf("%d", arr[score]);
	}

	return 0;
}
