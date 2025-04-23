#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<string> s;
	int n;
	cin >> n;
	s.emplace("ChongChong");
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (s.find(a) != s.end() || s.find(b) != s.end())
		{
			s.emplace(a);
			s.emplace(b);
		}
	}
	cout << s.size();
}