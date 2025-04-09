#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> vec;
	for (int i = m; i <= n; i++)
	{
		bool out = false;
		if (i == 0 || i == 1) continue;
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

	//for (auto& v : vec)
	//{
	//	cout << v << endl;
	//}

	cout << vec.size();
}