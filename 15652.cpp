#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;
vector<int> vec;
void back(int k)
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

	for (size_t i = k; i <= n; i++)
	{
			vec.emplace_back(i);
			back(i+1);
			vec.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	back(1);
}