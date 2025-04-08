#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int m;
	while (cin >> m)
	{
		if (m == 0) break;
		vector<int> vec;
		for (int i = m+1; i <= 2 * m; i++)
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

		cout << vec.size()<<endl;
		vec.clear();

	}
	

}