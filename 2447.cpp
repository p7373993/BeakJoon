#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void re(vector<vector<vector<vector<char>>>>& a, int n,int k)
{
	int num = pow(3, k);
	if (num > n) return;
	vector<vector<vector<vector<char>>>>temp(num);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			temp[i][j] = a;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		
	}
	re(a, n, k + 1);
}
int main()
{
	int n;
	cin >> n;
	vector<vector<char>> a(1);
	a[0][0] = '*';
	re(a, n, 1);
}