#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	set<int> s;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	vector<int> vec(m);
	for (auto& v : vec)
	{
		cin >> v;
	}
	for (const auto& v: vec)
	{
		if (s.find(v)== s.end())
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << 1 << ' ';
		}
	}

}