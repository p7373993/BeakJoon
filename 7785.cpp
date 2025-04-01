#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_set<string> set;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str1, str2;
		cin >> str1 >> str2;
		if (str2 == "enter")
		{
			set.insert(str1);
		}
		else if (str2 == "leave")
		{
			set.erase(str1);
		}
	}
	vector<string> vec(set.begin(), set.end());
	sort(vec.rbegin(), vec.rend());
	for (auto& v : vec)
	{
		cout << v << ' ';
	}
}