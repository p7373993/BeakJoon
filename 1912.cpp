#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num(100001);


int mn = INT_MIN;
int mx = INT_MIN;
int back(vector<vector<int>>& vec, int n, int m)
{
	if (n == m) return num[n];
	if (vec[n][m] == mn)
	{
		vec[n][m] = back(vec, n, ((m-n) / 2)) + back(vec, ((m-n) / 2) + 1, m);
	}
	if (mx < vec[n][m]) mx = vec[n][m];
	return vec[n][m];

}

		

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> sum(n+1,vector<int>(n+1,mn));
	for (size_t i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		num[i] = m;
	}

	back(sum, 1, n);
	cout << mx;
}