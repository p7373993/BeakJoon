#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> vec;
	vector<int> vec2;
	map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		int num;
		bool out = false;
		cin >> num;
		vec.push_back(num);
	}
	vec2 = vec;
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());

	for (int i = 0; i < vec2.size(); i++)
	{
		map[vec2[i]] = i;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << map[vec[i]]<<' ';
	}
	return 0;
}