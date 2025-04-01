#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<int, int> common;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++)
	{
		int n;
		cin >> n;
		common[n]++;
	}
	int nums=0;
	for (const auto& [word, count] : common)
	{
		if (count >= 2)
		{
			++nums;
		}
	}

	cout << n + m - (nums*2);
}