#include <iostream>
#include <vector>
using namespace std;

/*��ġ�� �κ��� ����
100 * ���� �� - ��ġ�� �κ�
���� 100* 100 �迭�� ���� ��ġ�� �κ��� 0���ΰ� ������
*/
int main() {
	vector<vector<bool>> array(100, vector<bool>(100, true));

	int num;
	int a = 0, b = 0;
	int size = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;
		for (int j = a; j < a+10; j++)
		{
			for (int k = b; k < b+10; k++)
			{
				array[j][k] = false;
			}
		}
	}
	for (const auto& vec : array)
	{
		for (const auto& plus : vec)
		{
			if (!plus) size++;
		}

	}
	cout << size;
}