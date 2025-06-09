//		dp[i] = max((dp[i- 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i]));dp[i-4] + stairs[i-2],stairs[i-1] 
#include <iostream>
#include <algorithm>

using namespace std;

int stairs[301];
int dp[301];

int main()
{
	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		stairs[i] = a;
	}
	dp[0] = stairs[0];
	if (n > 1) dp[1] = stairs[0] + stairs[1];
	if (n > 2) dp[2] = max(stairs[0] + stairs[1],max(stairs[0] + stairs[2], stairs[1] + stairs[2]));
	if (n > 3) dp[3] = max()
		01234

		1/1011
		0/1101
		1/0110

		0123

		1101
		1011
		0110
		1100

		012

		110
		101
		011
	for (size_t i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 4] + stairs[i - 2]+stairs[i - 1],max((dp[i - 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i])));
	}

	cout << dp[n - 1];
}