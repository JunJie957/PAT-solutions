/*
	��Ŀ������ 
	
		1011 A+B �� C (15��)

		�������� [?2^31,2^?31] �ڵ� 3 ������ A��B �� C�����ж� A+B �Ƿ���� C��

		�����ʽ��
		����� 1 �и��������� T (��10)���ǲ��������ĸ����������� T �����������ÿ��ռһ�У�˳����� A��B �� C���������Կո�ָ���

		�����ʽ��
		��ÿ�������������һ������� Case #X: true ��� A+B>C��������� Case #X: false������ X �ǲ��������ı�ţ��� 1 ��ʼ����

		����������
		4
		1 2 3
		2 3 4
		2147483647 0 2147483646
		0 -2147483648 -2147483647
    
		���������
		Case #1: false
		Case #2: true
		Case #3: true
		Case #4: false
*/

/*
	��Ŀ������
		
		(1) Ϊ�˱������������ת��˼·���ж� B > C - A �Ƿ���ȷ

		(2) ����Ҫע��ĵ��������ĸ�ʽҪ������ĿҪ��
*/

/*
	����ʵ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int a, b, c;
	for (int i = 0; i < T; ++i)
	{
		cin >> a >> b >> c;
		if (b > c - a)
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}
	return 0;
}
