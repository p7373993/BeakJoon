#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 1; i <= n; i++)
	{
		vec[i - 1] = i;
	}
	int index = 0;
	int gate = 1;
	while (index < vec.size()-1)
	{
		if (gate == 1)
		{
			gate = 2;
			++index;
		}
		else
		{
			gate = 1;
			vec.emplace_back(vec[index]);
			++index;
		}
	}
	cout << vec[index];
}