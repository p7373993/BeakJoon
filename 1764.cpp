#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> dic;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++)
	{
		string str;
		cin >> str;
		dic[str]++;
	}
	int num=0;
	vector<string> strs;
	for (auto& d : dic)
	{
		if (d.second >= 2)
		{
			num++;
			strs.emplace_back(d.first);
		}
	}
	cout << num<<'\n';

	for (auto& v : strs)
	{
		cout << v << endl;
	}

}