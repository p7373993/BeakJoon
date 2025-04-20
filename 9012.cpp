#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int num = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				++num;
			}
			else --num;
			if (num < 0)
			{
				cout << "NO\n";
				break;
			}
			if (i == str.size() - 1)
			{
				if(num ==0) cout << "YES\n";
				else cout << "NO\n";
				
			}
		}
	}
}