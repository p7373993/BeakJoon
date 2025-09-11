#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<long long> num(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	long long lo, hi;
	lo = 0;
	hi = *max_element(num.begin(), num.end());
	long long ans = 0;
	while(lo<=hi)
	{
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (num[i] > mid)
			{
				sum += num[i] - mid;
			}

		}

		if (sum == m)
		{
			ans = mid;
			break;
		}
		else if (sum > m)
		{
			lo = mid + 1;
			ans = mid;
		}
		else hi = mid - 1;
	}

	cout << ans;



	//1�� ���̴°� ����ð� �ɷ��� ����
	//logn�ð� ������ �̺� Ž������ ����
	//���� ������ ���������� lo hi ���ϱ�
}