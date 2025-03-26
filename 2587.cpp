#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec(5);
	int temp;
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		total += temp;
		vec[i] = temp;
	}
	sort(vec.begin(), vec.end());

	cout << total / 5 << endl << vec[2];
}
