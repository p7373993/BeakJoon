#include <iostream>

using namespace std;

int main()
{
//�밢�� ���� 2> 3 > 4 >5
	//Ȧ¦ �����ؼ� ��� �������� ����
	//¦�ϋ� ���ʺ���

	//�Ǻ���ġ ������ ���� �� ���ϱ�
	//�ٿ��� ��� ��ġ���� Ư��

	int n,ex;
	int temp = 0;
	int line;
	cin >> n;
	for (int i = 0; true; i++)
	{
		if (n <= temp) {
			line = i;
			ex = temp - i+1;
			break;
		}
		temp += i;
	}

	int a,b;
	a = temp - ex;
	b = n - ex;
	//temp = ���� ���ο� �ְ� ��
	//ex =�������ο� �ְ��
	//a = ���� ���ο� ���� ����
	//n- ex ���� for��

	if(line%2 ==0) cout << line - b << "/" << b;
	else cout << b << "/" << line - b;
	//cout <<temp<<endl<<ex<<endl<<line;
}