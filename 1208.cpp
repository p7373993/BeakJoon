#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 10;
	for (int test = 1; test <= t; test++)
	{
		int dump;
		cin >> dump;
		int height[100];
		for (int i = 0; i < 100; i++)
		{
			cin >> height[i];
		}

		while (dump--)
		{
			auto mx = max_element(height, height + 100);
			auto mn = min_element(height, height + 100);

			*mx = (*mx) - 1;
			*mn = (*mn) + 1;
		}

		auto mx = max_element(height, height + 100);
		auto mn = min_element(height, height + 100);

		cout <<"#"<<test<<" "<< (*mx) - (*mn)<<"\n";
	}

	return 0;
}