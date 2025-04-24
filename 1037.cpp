#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.emplace_back(a);
	}
	auto max = max_element(vec.begin(), vec.end());
	auto min = min_element(vec.begin(), vec.end());

	cout << (*max) * (*min);
}