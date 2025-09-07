#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int limit = INT_MIN;
vector<vector<int>> dp(1001, vector<int>(3, limit));
vector<vector<int>> colors(1001, vector<int>(3));

//int mn = INT_MAX;
//b[n] = amx(b[n-1] + an || an?)
int back(int idx,int color)
{
	if (idx == 1)
	{
		return colors[1][color];
	}
	if (dp[idx][color] == limit)
	{

		switch (color)
		{
		case 0:
			dp[idx][color] = min(back(idx - 1, 1), back(idx - 1, 2))+colors[idx][color];
			break;
		case 1:
			dp[idx][color] = min(back(idx - 1, 0), back(idx - 1, 2)) + colors[idx][color];
			break;
		case 2:
			dp[idx][color] = min(back(idx - 1, 0), back(idx - 1, 1)) + colors[idx][color];
			break;
		default:
			break;
		}
	}

	return dp[idx][color];
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> colors[i + 1][0];
		cin>>colors[i + 1][1];
		cin >> colors[i + 1][2];
	}
	//fill(dp.begin(), dp.end(), limit);
	int mn = min(min(back(n, 0), back(n, 1)), back(n, 2));
	cout << mn;
}