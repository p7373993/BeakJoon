#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int mn = INT_MIN;
vector<vector<int>>tree(502,vector<int>(502));
vector<vector<int>>dp(502, vector<int>(502,mn));

int back(int idx, int num)
{
	if (idx == 1)
	{
		return tree[1][1];
	}
	if (dp[idx][num] == mn)
	{
		if(num == 1)
		{
			dp[idx][num] = back(idx - 1, num)+tree[idx][num];
		}
		else if (num == idx)
		{
			dp[idx][num] = back(idx - 1, num-1) + tree[idx][num];
		}
		else
		{
			dp[idx][num] = max(back(idx - 1, num), back(idx - 1, num - 1)) + tree[idx][num];
		}
	}
	return dp[idx][num];
}

int main()
{
	cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			cin >> tree[i][j];
		}
	}

	int mx = INT_MIN;
	for (size_t i = 1; i <= n; i++)
	{
		mx = max(mx,back(n, i));
	}
	//int mx = *max_element(dp[n].begin(), dp[n].end());
	cout << mx;
}