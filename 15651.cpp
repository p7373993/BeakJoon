#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;

void back()
{
	if (vec.size() == m)
	{
		for (auto& v : vec)
		{
			cout << v << " ";

		}
		cout << "\n";
		return;
	}

	for (size_t i = 1; i <= n; i++)
	{

			vec.emplace_back(i);
			back();
			vec.pop_back();
		
	}
}
int main()
{
	cin >> n >> m;
	back();
}