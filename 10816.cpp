#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	unordered_map<int, int> dic;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		dic[num]++;
	}
	int m;
	cin >> m;
	for (int  i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << dic[num]<< ' ';
	}

}