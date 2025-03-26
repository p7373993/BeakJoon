#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n ,m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	cout << vec[n - m];
}