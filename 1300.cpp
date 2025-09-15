#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long count(long long num,long long n)
{
	long long ct = 0;
	for (long long i = 1; i <= n; i++)
	{
		ct += min(n, (num/i));
	}

	return ct;
}

int main()
{
	//3*3 10,000,000,000
	//1 2 2 3 3 4 6 6 9
	// �Ƹ� ���� ã�°� ���� �ִ°Ÿ� logn���� �ٲ� ����� �ʿ��ҵ� 
	//�ִ´ٴ°͵� �ּ� 10���ε� 2�� �ȿ� �Ұ���
	//�� ���� �ְ� �ű� �ε��� ã�°� �ƴ϶� 
	//k���� ���� ���ڸ��� ���߸� �ؾ��Ѵ�
	//���ݲ� �̺�Ž�� ������ ���� ���� ���ϰ� ���� ���ο� ���� ��Ž���� �ϴ� ����̿���
	// �׷��� B[k]�� lo, hi�� �ϴ� ���Ǹ� �ؾ��ϴµ� lo,hi�� ���� 1, n*n? �׷� mid �� �����̰�
	// mid �� ���ϰ� �̰� k��°�� �ش��ϴ�����? �̰� n������ ���� �޶�����
	// if n = 2 > 1 2 2 4 / ��Ģ���ֳ�?
	//n = 3 > 1 2 2 3 3 4 6 6 9
	// n= 4 > 1 2
	// 
	//ct(x) = min(n,x/i)
	//�׷��� ct ������ �̸� ���ϰ� �������� ��� ����
	long long  n;
	long long k;
	cin >> n >> k;

	long long lo = 1;
	long long hi = n * n;
	long long ans = 0;

	while(lo <= hi)
	{
		long long mid = lo + (hi - lo) / 2;
		long long ct;
		ct = count(mid, n);

		if (ct < k)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
			ans = mid;

		}
	}

	cout << ans;
}