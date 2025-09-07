#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int num[100001];
int dp[100001];
int mn = INT_MIN;
//b[n] = amx(b[n-1] + an || an?)
int back(int idx)
{
	if (idx == 0) return 0;
	if (dp[idx] == mn)
	{
		dp[idx] = max(back(idx - 1) + num[idx], num[idx]);
	}
	return dp[idx];
}

		

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i + 1];
	}
	fill(dp, dp + n+1, mn);
	back(n);
	int mx = *max_element(dp, dp + n+1);
	cout<<mx;
}