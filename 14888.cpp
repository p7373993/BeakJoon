#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
}