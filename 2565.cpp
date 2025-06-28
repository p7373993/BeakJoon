#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501];
int main()
{
	int n;
	cin >> n;
	vector < pair<int, int>> nums;
	for (size_t i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> temp = { a, b };
		nums.emplace_back(temp);
	}

	sort(nums.begin(), nums.end(), [&](pair<int, int>& a, pair<int, int>& b)
		{
			return a.first < b.first;
		}
	);

	int result = 0;
	for (size_t i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (size_t j = 0; j < i; j++)
		{
			if (nums[i].second > nums[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			result = max(result, dp[i]);
		}
	}

	cout << n - result;
}