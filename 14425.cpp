#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	set<string> s;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (s.find(str) != s.end()) result++;
	}
	cout << result;
}