/*
	��Ŀ������

		1002 д������� (20��)

		����һ�������� n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

		�����ʽ��
		ÿ������������� 1 ��������������������Ȼ�� n ��ֵ�����ﱣ֤ n С�� 10^100��

		�����ʽ��
		��һ������� n �ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ��� 1 �ո�
		��һ�������һ��ƴ�����ֺ�û�пո�

		����������
		1234567890987654321123456789

		���������
		yi san wu
*/


/*
	��Ŀ������

		(1) ����һ���������ֺ�ƴ��ת�������飺spell_str[10]
		(2) �ȱ���������ַ�����Ȼ��ÿһ���ַ�ת��Ϊ���֣�������
		(3) Ϊ��ʵ��������ֵ�ƴ����ʽ���ٴν�sumת��Ϊ�ַ����������������Ӧ�����ֵ�ƴ����ʽ
*/

/*
	����ʵ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// �ַ����飬�������ֺ�ƴ����ת��
string spell[10] = {
		"ling","yi", "er", "san",
		"si","wu","liu","qi","ba",
		"jiu"
};

int main()
{
	// ���ַ�������ʽ����
	string number;
	cin >> number;

	// ����ÿһλ���ܺ�
	int sum = 0;
	for (unsigned int i = 0; i < number.size(); ++i)
		sum += (number[i] - '0');

	// ��sum��ÿһλ������ƴ������ʽ���
	string tmp = to_string(sum);
	for (unsigned int i = 0; i < tmp.size() - 1; ++i)
		cout << spell[tmp[i] - '0'] << " ";

	// ���һλ�����������ո�
	cout << spell[tmp[tmp.size() - 1] - '0'];

	return EXIT_SUCCESS;
}
