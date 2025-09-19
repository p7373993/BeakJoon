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
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long temp;
	//long long result = LLONG_MIN;
	priority_queue<long long,vector<long long>, greater<long long>> pq;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> temp;
			//if (temp <= result) continue;
			pq.push(temp);
		}
		while (pq.size() > n)
		{
			pq.pop();
		}
		//result = pq.top();
	}

	cout << pq.top();
}