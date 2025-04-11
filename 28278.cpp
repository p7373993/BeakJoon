#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int a, b;
	cin >> n;
	vector<int> vec(n);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		
		cin >> a;
		switch (a)
		{
			case 1:
				cin >> b;
				vec[index] = b;
				++index;
				break;
			case 2:
				if (index <= 0)
				{
					cout << "-1\n";
				}
				else
				{
					cout << vec[index - 1] << "\n";
					--index;
				}
				break;
			case 3:
				cout << index << "\n";
				break;
			case 4:
				if (index == 0) cout << "1\n";
				else cout << "0\n";
				break;
			case 5:
				if (index <= 0)
				{
					cout << "-1\n";
				}
				else
				{
					cout << vec[index-1]<< "\n";
				}
				break;

		}

	}
}
