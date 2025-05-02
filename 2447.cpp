#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void re(vector<string>& a,int n , int k)
{
	if (n == k) return;
	n *= 3;
	for (size_t i = 0; i < (n*2)/3; i++)
	{
		a.emplace_back(a[i%n]);
	}
	for (size_t i = 0; i < n; i++)
	{
		a[i] = a[i] + a[i] + a[i];
	}

	for (size_t i = (n/3); i < (n*2/3); i++)
	{
		for (size_t j = (n / 3); j < (n * 2 / 3); j++)
		{
			a[i][j] = ' ';
		}
	}

	re(a, n, k);
}

int main()
{
	int n;
	cin >> n;
	vector<string> vec(1, "*");
	 
	re(vec, 1, n);

	for (auto& a : vec)
	{
		cout << a <<"\n";
	}
}