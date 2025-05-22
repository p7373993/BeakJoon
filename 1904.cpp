//GPT도움 받음
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m;
int num[1000001];
//num[n]=num[n-1]+num[n-2]
int back(int n)
{
	
	if (num[n] == -1)
	{
		num[n] = (back(n - 1) + back(n - 2)) % 15746;
	}
	return num[n];
}
int main()
{
	cin >> m;
	fill(num, num + 1000001, -1);
	num[1] = 1;
	num[2] = 2;
	int counts = back(m);
	cout << counts;
}