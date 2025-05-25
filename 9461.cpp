#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int num[101];
long long int back(int n)
{

	if (num[n] == -1)
	{
		num[n] = (back(n - 1) + back(n - 5));
	}
	return num[n];
}


int main()
{
	//f[n] =f[n-1]+f[n-5] 
	fill(num, num + 101, -1);
	int m;
	cin >> m;
	num[1] = 1;
	num[2] = 1;
	num[3] = 1;
	num[4] = 2;
	num[5] = 2;
	for (size_t i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cout << back(a) << endl;
	}
}