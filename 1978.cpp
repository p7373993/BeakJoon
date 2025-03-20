#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int result = 0;
	for (auto& v : vec)
	{
		if (v == 1)
		{
			result++;
			continue;
		}
			for (int i = 2; i < v-1; i++)
		{
			if (v % i == 0)
			{
				result++;
				break;
			}

		}
	}
	cout << n-result;
}