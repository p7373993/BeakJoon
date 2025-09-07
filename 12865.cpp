#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101][100001];
int main()
{
	vector<pair<int, int>> num;
	int n, w;
	cin >> n >> w;
	for (size_t i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int,int> temp =  { a,b };
		num.emplace_back(temp);
	}
	
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= w; j++)
		{
			if (j < num[i-1].first)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - num[i-1].first] + num[i-1].second);
			}
		}
	}

	cout << dp[n][w];
}