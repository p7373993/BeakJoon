#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<string>> vec(201);

	int n;
	int num;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> name;
		vec[num].push_back(name);
	}
	
	for (int i = 1; i < 201; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << i << ' ' << vec[i][j]<< endl;
		}
	}
}