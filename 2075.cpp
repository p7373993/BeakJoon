//n*n��� ���� ������ ������?
//n�� ������� ���� ���� ������
//�ϴ� n���� ���� �ִ´� 
//���⼭ �� n���� ���ڸ� ������� �װ� ���� ū�Ŵ� ����
//�����ҋ� �׿��� ���� ����

//�� ū�ź��� �ؾ��ϳ� �׷��� �ݴ��?
//ex) 52 49 41 32 20+(48 35 28 25) > 52 49 48 41 35/���⼭ �ڸ��� �׷��� n*n��ȸ�� �ϰ����� ������ ���Ѵ�?
//O(2n*n) +a 


// ���� ���ۺ��� pq�ϸ� (n*n*logn)

//8��Ƽ�� * 100����? 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	priority_queue<long long> pq;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<long long>> vec(n,vector<long long>(n));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin>>vec[i][j];
		}
	}

	//�� �� ���� ������ ������� �� ����?
	//�� �ึ�� 5��° �Ʒ��δ´� �̾ƹ����� �ݺ�?
}