#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int n;
	char c;

	cin >> n >> c;

	
	n -= 1;
	int line = 1;
	int base = 3;

	// �������õ����ٸ�����
	while (n >= base * 2)
	{
		n -= base * 2;
		base += 2;	
		line += 2;	// ��������
	}

	int space = 0;
	int start = line;
	for (int i = 1; i <= line; ++i)
	{
		// ������ո�
		for (int k = 0; k < space; ++k)  cout << " ";
		
		// �������
		for (int j = start; j >= 1; --j) cout << c;
		
		// ����
		cout << endl;

		// ÿ��ӡһ�о�Ҫ���¿ո����Ҫ��ӡ�ķ��ŵ�����
		if (i <= line / 2)
		{
			start -= 2;
			space++;
		}
		else
		{
			start += 2;
			space--;
		}
	}
	// ��ӡʣ��δʹ�÷��ŵ�����
	cout << n << endl;	
	return 0;
}
