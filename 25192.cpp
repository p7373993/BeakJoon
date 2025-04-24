#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<string> s;
	size_t n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "ENTER")
		{
			sum += s.size();
			s.clear();
		}
		else
		{
			s.emplace(str);
		}
	}
	sum += s.size();

	cout << sum;
}