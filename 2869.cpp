#include <iostream>

using namespace std;

int main()
{
	//�Ϸ翡 a-b ��ŭ �����δ�
	//a-b �� v�� �Ѵ´ٸ� �� ���Ŀ�?
	//v-a �� 
	//(V-A) % (A-B) == 0 �ϋ��� ����ó���ض�
	long long a, b, v;
	int total = 0;
	cin >> a >> b >> v;
	if ((v - a) % (a - b) == 0)
	{
		total = (v - a) / (a - b) +1 ;
	}
	else total = (v - a) / (a - b)+2;

	cout << total;
}