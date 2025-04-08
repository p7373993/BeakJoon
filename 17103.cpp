#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		int m;
		cin >> m;
		vector<int> vec;
		for (int i = 2; i <m; i++)
		{
			bool out = false;
			if (i == 1) continue;

			for (int j = 2; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					out = true;
					break;
				}

			}
			if (!out)
			{
				vec.emplace_back(i);
			}
		}
		int num = 0;
		for (int a = 0; a < vec.size(); a++)
		{
			if (vec[a] > (m / 2))
			{
				break;
			}
			for (int b = vec.size()-1; b >=a; b--)
			{

				if (vec[a] + vec[b] == m)
				{
					num++;
					break;
				}

			}

		}
		cout << num << endl;
	}
}
//19 23 / 17 29 / 13 31 /11 37 /7 41 /5 43
//
//2나눠서 순서대로?
