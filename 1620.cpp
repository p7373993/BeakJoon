#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_map<string, int> dic;
	unordered_map<int, string> dic2;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		dic[str] = i+1;
		dic2[(i + 1)] = str;
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (isdigit(str[0]))
		{
			cout << dic2[stoi(str)] << '\n';
		}
		else
		{
			cout << dic[str] << '\n';
		}
	}
	
}