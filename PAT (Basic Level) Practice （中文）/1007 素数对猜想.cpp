/*
	��Ŀ������

		1007 �����Բ��� (20��)
		
		�������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

		�ָ�������������N(<10^5)������㲻����N���������������Եĸ�����

		�����ʽ:
		������һ�и���������N��

		�����ʽ:
		��һ�������������N���������������Եĸ�����

		��������:
		20

		�������:
		4
*/

/*
	��Ŀ������
		
		(1) ������5-n���������֣��ж�i-2��i�Ƿ�������������ǣ������+1

		(2) �����жϣ�ֻ���жϵ�ǰ����ֵ��һ�뼴��
*/

/*
	����ʵ��
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int val)
{
	for (int i = 2; i * i <= val; ++i)
		if (val % i == 0) return false;
	return true;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 5; i <= n; ++i)
		if (isPrime(i - 2) && isPrime(i)) ++count;
	
	cout << count;
	return 0;
}
