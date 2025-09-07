#include <iostream>
#include <algorithm>
#include <vector>
//f(n) = min(f(n-1),f(n/3),f(n/2))+1
using namespace std;

int main()
{
	//int dp[1000001];
	vector<int> dp(1000001);
	int n;
	cin>> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (size_t i = 4; i <= n; i++)
	{
		if (i % 3 == 0 && i % 2 == 0)
		{
			dp[i] = min(dp[i - 1], min(dp[i / 3], dp[i / 2])) + 1;
			continue;
		}
		if (i % 3==0)
		{
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else if (i % 2 == 0)
		{
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
		}

	}

	cout << dp[n];
}