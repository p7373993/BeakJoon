#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1001][1001];
int main()
{
//dp[n] = dp[n-1] +1
	string a;
	string b;
	cin >> a >> b;

	for (size_t i = 0; i < 1001; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for (size_t i = 1; i < size(a)+1; i++)
	{
		for (size_t j = 1; j < size(b)+1; j++)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[size(a)][size(b)];
}