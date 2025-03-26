#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,a;
	int temp;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 0; i < vec.size()-1; i++)
	{
		for (int j = 0; j < vec.size()-1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	}

	for (auto& v : vec)
	{
		cout << v << endl;;
	}
}