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



	//1씩 줄이는건 상수시가 걸려서 빡셈
	//logn시간 나오게 이분 탐색으로 진행
	//이전 문제와 마찬가지로 lo hi 정하기
}