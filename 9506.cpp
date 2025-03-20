#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a;
	vector<int> vec;
	while (cin >> a)
	{
		vec.clear();
		int sum = 0;
		if (a == -1) return 0;

		for (int i = 1; i < a; i++)
		{
			if (a % i == 0)
			{
				sum += i;
				vec.push_back(i);
			}
			if (i == (a - 1))
			{
				if (sum == a)
				{
					cout << a << " = " << "1";
					for (auto v : vec)
					{
						if (v == 1) continue;
						cout << " + " << v;
					}
					cout << endl;
				}
				else
				{
					cout << a << " is NOT perfect." << endl;
				}
			}
		}
		
	}
}
