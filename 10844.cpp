#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000000;
int dp[101][10];

int main()
{
	int n;
	cin >> n;
	dp[1][0] = 0;
	for (size_t i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (size_t i = 2; i <= n; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1] % MOD;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][8] % MOD;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
	int sum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum = (sum + dp[n][i]) % MOD;  // ← 여기서도 누적하면서 %MOD 필요!
	}
	cout << sum % MOD;
}
